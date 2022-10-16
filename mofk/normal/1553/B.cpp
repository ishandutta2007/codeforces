#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s, t;
        cin >> s >> t;
        string ans = "NO";
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size() && j < i + t.size(); ++j) {
                int ok = 1, idx = i, dir = 1;
                for (int z = 0; z < t.size(); ++z) {
                    if (idx < 0 || s[idx] != t[z]) {
                        ok = 0;
                        break;
                    }
                    if (idx == j) dir = -1;
                    idx += dir;
                }
                if (ok) {
                    ans = "YES";
                    break;
                }
            }
            if (ans == "YES") break;
        }
        cout << ans << '\n';
    }
    return 0;
}