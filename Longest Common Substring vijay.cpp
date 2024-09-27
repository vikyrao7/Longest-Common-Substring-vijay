#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;

// Function to find the longest common substring using dynamic memory allocation
string longestCommonSubstring(const string& str1, const string& str2, int& maxLength) {
    int length1 = str1.length();
    int length2 = str2.length();

    // Create a 2D array dynamically using pointers
    int** lookupTable = new int*[length1 + 1];
    for (int i = 0; i <= length1; ++i) {
        lookupTable[i] = new int[length2 + 1];
    }

    // Initialize all elements to 0
    for (int i = 0; i <= length1; ++i) {
        for (int j = 0; j <= length2; ++j) {
            lookupTable[i][j] = 0;
        }
    }

    maxLength = 0; // Length of the longest common substring
    int endIndex = 0;  // Ending index of the longest common substring in str1

    // Fill the lookup table
    for (int i = 1; i <= length1; ++i) {
        for (int j = 1; j <= length2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;
                
                // Update the max length and ending index if needed
                if (lookupTable[i][j] > maxLength) {
                    maxLength = lookupTable[i][j];
                    endIndex = i - 1;
                }
            } else {
                lookupTable[i][j] = 0;
            }
        }
    }

    // Display the lookup table in a formatted way
    cout << "\nLookup Table:" << endl;

    // Print column headers
    cout << "     "; // Space for row headers
    for (int j = 0; j < length2; ++j) {
        cout << setw(3) << str2[j];
    }
    cout << endl;

    // Print the table with row headers
    for (int i = 0; i <= length1; ++i) {
        if (i > 0)
            cout << setw(3) << str1[i - 1] << " "; // Print row header
        else
            cout << "    "; // Empty space for the top-left corner
        
        for (int j = 0; j <= length2; ++j) {
            cout << setw(3) << lookupTable[i][j];
        }
        cout << endl;
    }

    // Extract the longest common substring
    string longestSubstring = str1.substr(endIndex - maxLength + 1, maxLength);

    // Free the allocated memory
    for (int i = 0; i <= length1; ++i) {
        delete[] lookupTable[i];
    }
    delete[] lookupTable;

    return longestSubstring;
}

int main() {
    // Input strings from the user
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    // Check if both strings are of the same length
    if (str1.length() != str2.length()) {
        cout << "Error: The strings must be of the same length. Please try again." << endl;
        return 1;
    }

    int maxLength;
    
    // Find the longest common substring
    string result = longestCommonSubstring(str1, str2, maxLength);

    // Output the result
    cout << "\nResult Summary:" << endl;
    cout << "----------------------------------" << endl;
    cout << "First String: " << str1 << endl;
    cout << "Second String: " << str2 << endl;
    cout << "Longest Common Substring: \"" << result << "\"" << endl;
    cout << "Length of Longest Common Substring: " << maxLength << endl;
    cout << "----------------------------------" << endl;
    
    return 0;
}
