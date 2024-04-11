#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, 1e9);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        dp[x] = 0;
    }
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](const auto &self, int v, int p) -> void {
        for (int u : g[v]) {
            if (u == p)
                continue;
            self(self, u, v);
            dp[v] = min(dp[v], dp[u] + 1);
        }
    };
    dfs(dfs, 1, 0);
    auto pfs = [&](const auto &self, int v, int p, int h) -> bool {
        bool res = false;
        for (int u : g[v]) {
            if (u == p)
                continue;
            if (h + 1 < dp[u])
                res |= self(self, u, v, h + 1);
        }
        if (g[v].size() == 1 && v != 1)
            res = true;
        return res;
    };
    if (pfs(pfs, 1, 0, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}