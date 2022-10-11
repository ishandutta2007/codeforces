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

void solve(int test_num) {
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
    
    vector<int> sz(n), dp(n);

    y_combinator([&](auto dfs, int v) -> void {
        sz[v] = 1;
        if (g[v].empty()) return;

        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            sz[v] += sz[u];
        }

        if (len(g[v]) == 1) {
            dp[v] = sz[g[v][0]] - 1;
        } else {
            assert(len(g[v]) == 2);
            dp[v] = max(sz[g[v][0]] - 1 + dp[g[v][1]], sz[g[v][1]] - 1 + dp[g[v][0]]);
        }
    })(0);

    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}