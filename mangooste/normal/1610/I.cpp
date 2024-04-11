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

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> dp(n), par(n);

    y_combinator([&](auto dfs, int v) -> void {
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            par[u] = v;
            dfs(u);
            dp[v] ^= dp[u] + 1;
        }
    })(0);

    vector<bool> used(n);
    used[0] = true;
    cout << (dp[0] ? 1 : 2);

    int cur = dp[0], edges = 0;
    for (int v = 1; v < n; v++) {
        for (int u = v; !used[u]; u = par[u]) {
            for (auto w : g[u]) {
                if (!used[w]) cur ^= dp[w] + 1;
            }

            if (used[par[u]]) cur ^= dp[u] + 1;
            used[u] = true;
            edges++;
        }
        cout << ((cur ^ (edges & 1)) ? 1 : 2);
    }
    cout << '\n';
}