#include <bits/stdc++.h>
using namespace std;
string s;
int fi[26];
int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 26; i++) fi[i] = 1000;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        fi[s[i] - 'a'] = min(fi[s[i] - 'a'], i);
    }
    for (int i = 0; i + 1 < 26; i++) {
        if (fi[i] > fi[i + 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}