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

    vector<vector<pair<int, int>>> queries(n);
    int q;
    cin >> q;
    for (int id = 0; id < q; id++) {
        int v, k;
        cin >> v >> k;
        queries[v - 1].emplace_back(k, id);
    }

    vector<int> ans(q);    

    y_combinator([&](auto dfs, int v) -> vector<int> {
        vector<int> res;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            auto cur = dfs(u);
            if (len(cur) > len(res)) swap(cur, res);
            for (int i = 0; i < len(cur); i++) {
                res[i] += cur[i];
            }
        }

        for (auto [k, id] : queries[v]) {
            ans[id] = (k >= len(res) ? 0 : res[k]) + len(g[v]);
        }

        int cur = len(g[v]) - 1;
        if (len(res) < cur) res.resize(cur);
        for (int i = 0; i < len(res); i++) {
            res[i] += cur - i;
            if (res[i] < 0) {
                res.resize(i);
                break;
            }
        }
        return res;
    })(0);

    for (auto x : ans) cout << x << '\n';
}