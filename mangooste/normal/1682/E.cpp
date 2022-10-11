#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (auto &x : p) cin >> x, x--;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }

    vector<int> id(n, -1), ans;
    for (int i = 0; i < n; i++) {
        if (id[i] != -1) continue;
        vector<int> cycle;
        for (int j = i; id[j] == -1; j = p[j]) {
            id[j] = len(cycle);
            cycle.push_back(j);
        }

        for (auto v : cycle) {
            sort(all(g[v]), [&](const auto a, const auto b) {
                return (id[a.first] - id[v] + len(cycle)) % len(cycle) < (id[b.first] - id[v] + len(cycle)) % len(cycle);
            });
        }

        y_combinator([&](auto dfs, int v, int p) -> void {
            for (auto &[u, i] : g[v]) {
                if (u == p) {
                    ans.push_back(i);
                } else {
                    dfs(u, v);
                }
            }
        })(cycle[0], -1);
    }

    assert(len(ans) == m);
    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << " \n"[i == m - 1];
    }
}