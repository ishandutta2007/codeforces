#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

const int N = 105;
const int M = 26;

int dp[N][N][M][2];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--, b--, c -= 'a';
        g[a].emplace_back(b, c);
    }
    vector<int> order;
    vector<int> used(n);
    auto dfs = [&](auto self, int v) -> void {
        used[v] = 1;
        for (auto [u, _] : g[v])
            if (!used[u])
                self(self, u);
        order.push_back(v);
    };
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(dfs, i);
    // reverse(order.begin(), order.end());
    for (int last = 25; last >= 0; last--) {
        for (int i : order)
            for (int j : order) {
                for (auto [u, c] : g[i])
                    if (c >= last)
                        dp[i][j][last][0] |= !dp[u][j][c][1];
                for (auto [u, c] : g[j])
                    if (c >= last)
                        dp[i][j][last][1] |= !dp[i][u][c][0];
            }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (dp[i][j][0][0] ? 'A' : 'B');
        cout << '\n';
    }
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