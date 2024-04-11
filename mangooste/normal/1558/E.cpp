#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];

    vector<vector<int>> g(n);
    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    auto initial_g = g;

    auto good = [&](int x) {
        g = initial_g;
        vector<int> par(n);
        iota(all(par), 0);

        auto root = y_combinator([&](auto root, int v) -> int {
            return par[v] == v ? v : par[v] = root(par[v]);
        });

        auto unite = [&](int v, int u) {
            v = root(v);
            u = root(u);
            if (v == u) return;
            if (len(g[v]) < len(g[u])) swap(v, u);
            par[u] = v;
            for (auto x : g[u]) g[v].push_back(x);
            g[u].clear();
            g[u].shrink_to_fit();
        };

        while (true) {
            bool ok = true;
            for (int i = 1; i < n; i++) {
                ok &= root(i) == root(0);
            }
            if (ok) return true;

            ll cur = x;
            for (int i = 1; i < n; i++) {
                if (root(i) == root(0)) cur += b[i];
            }

            vector<int> used(n, -1), pr(n, -1);
            
            bool fnd = y_combinator([&](auto dfs, int v, int p, ll cur) -> bool {
                if (used[v] != -1) {
                    for (; v != -1; v = pr[v]) {
                        unite(0, v);
                    }
                    return true;
                }

                used[v] = 0;
                for (auto u : g[v]) {
                    int x = a[u], y = b[u];
                    u = root(u);
                    if (v == u || u == p || x >= cur) continue;

                    if (used[u] != 0) pr[u] = v;
                    if (dfs(u, v, cur + y)) {
                        unite(0, v);
                        return true;
                    }
                }
                used[v] = 1;
                return false;
            })(root(0), -1, cur);

            if (!fnd) return false;
        }
        assert(false);
    };

    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (good(mid) ? r : l) = mid;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}