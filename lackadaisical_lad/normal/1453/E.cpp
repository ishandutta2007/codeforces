// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 1;
    vector<int> used(n), dp(n);
    function<void(int)> dfs =[&](int v) {
        used[v] = 1;
        vector<int> h;
        for (int u : g[v]) {
            if (!used[u]) {
                dfs(u);
                h.push_back(dp[u]);
            }
        }
        if (h.empty()) return;
        sort(h.begin(), h.end());
        if (v) {
            if (h.size() > 1)
                ans = max(ans, h.back() + 2);
            dp[v] = h[0] + 1; 
        } else {
            ans = max(ans, h.back() + 1);
            if (h.size() > 1) {
                ans = max(ans, h[h.size() - 2] + 2);
            }
        }
    };
    dfs(0);
    cout << ans << '\n';
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