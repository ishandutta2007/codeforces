#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
using LL = long long;

string s, t;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        cin >> t;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int cur = 0;
        for (int i = 0; i < t.length(); i += 1) {
            while (cur < s.length() && s[cur] != t[i]) {
                cur += 2;
            }
            if (i != t.length() - 1)
                cur++;
        }
        if (cur < s.length()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
/*
ABABABABAB
4433221100
544
*/