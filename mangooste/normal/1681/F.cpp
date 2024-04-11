#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
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

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--, w--;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }

    vector<int> sz(n), dp_down(n), sum_down(n), tot_sum(n);

    y_combinator([&](auto dfs, int v) -> void {
        sz[v] = 1;
        for (auto &[u, w] : g[v]) {
            g[u].erase(find(all(g[u]), pair{v, w}));
            int tot = -tot_sum[w];
            dfs(u);
            sz[v] += sz[u];
            tot += tot_sum[w];

            sum_down[u] = tot;
            dp_down[u] = sz[u] - tot;
            tot_sum[w] += dp_down[u];
        }
    })(0);

    vector<int> dp_up(n);

    y_combinator([&](auto dfs, int v) -> void {
        for (auto &[u, w] : g[v]) {
            dp_up[u] = (n - sz[u]) - (tot_sum[w] - dp_down[u] - sum_down[u]);
            tot_sum[w] -= dp_down[u];
            tot_sum[w] += dp_up[u];
            dfs(u);
            tot_sum[w] -= dp_up[u];
            tot_sum[w] += dp_down[u];
        }
    })(0);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1ll * dp_down[i] * dp_up[i];
    }
    cout << ans << '\n';
}