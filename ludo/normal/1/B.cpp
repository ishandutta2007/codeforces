#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char token;
    cin.get(token);
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        unsigned int r = s.find('R');
        unsigned int c = s.find('C');

        bool is_rxcy = r != string::npos && c != string::npos && r + 1 < c;
        if (is_rxcy) {
            for (unsigned int j = r + 1; j < c; j++) {
                if (s[j] < '0' || s[j] > '9') {
                    is_rxcy = false;
                    break;
                }
            }
        }
        if (is_rxcy) {
            // RXCY notation
            int row = 0, col = 0;
            for (unsigned int j = r + 1; j < c; j++) {
                row = row * 10 + (s[j] - '0');
            }
            for (unsigned int j = c + 1; j < s.size(); j++) {
                col = col * 10 + (s[j] - '0');
            }

            stack<char> colChars;
            while (col > 0) {
                if (col %26 == 0) {
                    colChars.push('Z');
                    col -= 26;
                } else {
                    colChars.push((col % 26) + 'A' - 1);
                }
                col /= 26;
            }
            while (!colChars.empty()) {
                cout << colChars.top();
                colChars.pop();
            }
            cout << row << endl;
        } else {
            // CCC RRR
            bool is_col = true;
            int row = 0, col = 0;
            for (unsigned int j = 0; j < s.size(); j++) {
                if ('0' <= s[j] && s[j] <= '9') {
                    is_col = false;
                }
                if (is_col) {
                    col = col * 26 + s[j] - 'A' + 1;
                }
                if (!is_col) {
                    assert('0' <= s[j] && s[j] <= '9');
                    row = row * 10 + s[j] - '0';
                }
            }
            cout << "R" << row << "C" << col << endl;
        }
    }
    return 0;
}