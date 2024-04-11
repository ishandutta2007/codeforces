#include <bits/stdc++.h>

#include <utility>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n * n, vector<int>());
    vector<vector<bool>> m(n * n, vector<bool>(n * n));
    auto link = [&](int u, int v) {
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        m[u][v] = m[v][u] = true;
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            for (int k = 1; k <= n; ++k) {
                char c;
                cin >> c;
                if (c == '1') link((i - 1) * n + k, (i + j - 1) * n + k);
            }
        }
    }
    int c = 0;
    vector<int> comp(n * n, -1);
    auto permute = [&](int x) { return (x % n) * n + x / n; };
    auto dfs = [&](auto dfs, int cur, int c) -> void {
        if (comp[cur] == c) return;
        comp[cur] = c;
        for (int next: g[cur]) dfs(dfs, next, c);
        dfs(dfs, permute(cur), c);
    };
    for (int i = 0; i < n * n; ++i) if (comp[i] == -1) dfs(dfs, i, c++);
    for (int k = 0; k < c; ++k) {
        vector<vector<int>> tree(n);
        int cnt = 0;
        for (int i = 0; i < n * n; ++i) {
            if (i % n <= i / n) continue;
            if (comp[i] == k) {
                tree[i / n].push_back(i % n);
                tree[i % n].push_back(i / n);
                cnt++;
            }
        }
        if (cnt != n - 1) continue;
        vector<vector<int>> d(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) d[i][i] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j: tree[i]) d[i][j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    d[j][k] = min(d[j][i] + d[i][k], d[j][k]);
                }
            }
        }
        bool ok = all_of(d[0].begin(), d[0].end(), [&](int x) { return x < n; });
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((i != k && d[i][j] == d[k][j]) != m[i * n + j][k * n + j]) ok = false;
                }
            }
        }
        if (ok) {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i) {
                for (int j: tree[i]) {
                    if (j < i) cout << i + 1 << ' ' << j + 1 << '\n';
                }
            }
            return;
        }
    }
    cout << "No\n";
}