#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> h(n + 1), p(n + 1), deg(n + 1);
    h[1] = 1;
    auto dfs = [&](auto self, int v) -> void {
        for (int u : g[v]) {
            if (h[u])
                continue;
            deg[v]++;
            h[u] = h[v] + 1;
            p[u] = v;
            self(self, u);
        }
    };
    dfs(dfs, 1);
    for (int i = 1; i <= n; i++) {
        if (h[i] >= (n + k - 1) / k) {
            cout << "PATH\n";
            cout << h[i] << '\n';
            for (int v = i; v; v = p[v])
                cout << v << ' ';
            cout << '\n';
            return;
        }
    }
    vector<int> leaves;
    for (int i = 1; i <= n; i++)
        if (leaves.size() < k && deg[i] == 0)
            leaves.push_back(i);
    assert(leaves.size() == k);
    cout << "CYCLES\n";
    for (int leaf : leaves) {
        int anc1 = -1, anc2 = -1;
        vector<int> cycle;
        for (int u : g[leaf]) {
            if (h[u] + 1 == h[leaf])
                continue;
            if ((h[leaf]  - h[u] + 1) % 3) {
                for (int v = leaf; v != p[u]; v = p[v])
                    cycle.push_back(v);
                break;
            }
            if (anc1 == -1)
                anc1 = u;
            else if (anc2 == -1)
                anc2 = u;
        }
        if (cycle.empty()) {
            assert(anc1 != -1 && anc2 != -1);
            cycle.push_back(leaf);
            if (h[anc1] < h[anc2])
                swap(anc1, anc2);
            for (int v = anc1; v != p[anc2]; v = p[v])
                cycle.push_back(v);
        }
        assert(cycle.size() % 3);
        cout << cycle.size() << '\n';
        for (int v : cycle)
            cout << v << ' ';
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