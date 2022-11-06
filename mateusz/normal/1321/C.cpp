#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    for (int c = 'z'; c >= 'a'; c--) {
        string newS;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c && !newS.empty() && newS.back() + 1 == s[i]) {
                continue;
            }
            newS += s[i];
        }
        s = newS;
        newS = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == c && !newS.empty() && newS.back() + 1 == s[i]) {
                continue;
            }
            newS += s[i];
        }
        reverse(newS.begin(), newS.end());
        s = newS;
    }
    cout << n - s.size() << endl;
}