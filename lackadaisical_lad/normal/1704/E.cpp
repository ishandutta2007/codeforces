#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> g(n);
    vector<int> order;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }
    vector<int> used(n);
    auto dfs = [&](auto self, int v) -> void {
        used[v] = 1;
        for (int u : g[v])
            if (!used[u])
                self(self, u);
        order.push_back(v);
    };
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(dfs, i);
    reverse(order.begin(), order.end());
    ll ans = 0;
    for (int iter = 0; iter < 2005; iter++) {
        vector<int> S;
        for (int i = 0; i < n; i++)
            if (a[i])
                S.push_back(i);
        if (S.empty())
            break;
        ans++;
        for (int v : S) {
            a[v]--;
            for (int u : g[v])
                a[u]++;
        }
    }
    const int MOD = 998244353;
    for (int v : order) {
        a[v] %= MOD;
        for (int u : g[v])
            (a[u] += a[v]) %= MOD;
    }
    cout << (ans + a[order.back()]) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}