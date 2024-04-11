#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> nxt[2];
    nxt[0].assign(n + 3, n);
    nxt[1].assign(n + 3, n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            if (s[i] - '0' == j) {
                nxt[j][i] = i;
            } else {
                if (i + 1 < n) {
                    nxt[j][i] = nxt[j][i + 1];
                }
            }
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        bool kek = true;
        for (int bad = l + 1; bad <= r; bad++) {
            int pos = -1;
            for (int i = l; i <= r && pos < n; i++) {
                if (i == bad) {
                    pos = nxt[s[i] - '0'][pos + 2];
                } else {
                    pos = nxt[s[i] - '0'][pos + 1];
                }
            }
            if (pos < n) {
                cout << "YES\n";
                kek = false;
                break;
            }
        }
        if (kek) cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}