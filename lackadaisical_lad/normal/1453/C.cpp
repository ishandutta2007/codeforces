#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

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

void calc(int n, vector<string>& a, vector<int>& best) {
    for (char d = '0'; d <= '9'; d++) {
        int mn = n, mx = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == d) {
                    mn = min(mn, j);
                    mx = max(mx, j);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int fst = -1;
            for (int i = 0; i < n; i++) {
                if (a[i][j] != d) {
                    continue;
                }
                int h = max(n - 1 - i, i);
                int w = max(mx - j, j - mn);
                if (h > 0 && w > 0)
                    best[d - '0'] = max(best[d - '0'], h * w);
                if (fst != -1) {
                    h = i - fst;
                    w = max(n - 1 - j, j);
                    best[d - '0'] = max(best[d - '0'], h * w);
                }
                if (fst == -1) fst = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> best(10);
    calc(n, a, best);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(a[i][j], a[j][i]);
        }
    }    
    calc(n, a, best);
    for (int i : best) {
        cout << i << ' ';
    }
    cout << '\n';
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