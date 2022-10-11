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
    if (n == 1) {
        cout << "0\n";
        return;
    }

    vector<int> dp(n), deg(n);

    auto query = [&](int v) {
        return dp[v] + max(0, deg[v] - 1);
    };

    auto add = [&](int v, int u, int coeff) {
        dp[v] += query(u) * coeff;
        deg[v] += (query(u) == 0) * coeff;
    };

    y_combinator([&](auto dfs, int v) -> void {
        if (g[v].empty()) return;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            add(v, u, 1);
        }
    })(0);

    int ans = n;

    y_combinator([&](auto dfs, int v) -> void {
        ans = min(ans, query(v) + 1);
        for (auto u : g[v]) {
            add(v, u, -1);
            add(u, v, 1);
            dfs(u);
            add(u, v, -1);
            add(v, u, 1);
        }
    })(0);

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}