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

    vector<int> sz(n);
    vector<bool> used(n);
    string answer(n, 'A');

    y_combinator([&](auto dfs, int v, int depth) -> void {
        y_combinator([&](auto dfs, int v, int p) -> void {
            sz[v] = 1;
            for (auto u : g[v])
                if (!used[u] && u != p) {
                    dfs(u, v);
                    sz[v] += sz[u];
                }
        })(v, v);

        int tot = sz[v];

        v = y_combinator([&](auto dfs, int v, int p) -> int {
            for (auto u : g[v])
                if (!used[u] && u != p && sz[u] * 2 > tot)
                    return dfs(u, v);

            return v;
        })(v, v);

        answer[v] = 'A' + depth;
        used[v] = true;

        for (auto u : g[v])
            if (!used[u])
                dfs(u, depth + 1);
    })(0, 0);

    for (int i = 0; i < n; i++)
        cout << answer[i] << " \n"[i == n - 1];
}