#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int bal = 0;
        int x = 0, y = 0;
        auto consume = [&](int pos) {
            if (s[pos] == '(') {
                // if (bal >= 2 && x) {
                //     x--;
                //     y++;
                //     bal -= 2;
                // }
                bal++;
            } else if (s[pos] == ')') {
                if (bal == 0 && y) {
                    y--;
                    x++;
                    bal += 2;
                }
                bal--;
            } else if (s[pos] == '?') {
                if (bal > 0) {
                    y++;
                    bal--;
                } else {
                    x++;
                    bal++;
                }
            }
        };
        for (int j = i + 1; j < n; j += 2) {
            consume(j - 1);
            if (bal < 0)
                break;
            consume(j);
            if (bal < 0)
                break;
            if (bal == 0)
                ans++;
        }
    }    
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}