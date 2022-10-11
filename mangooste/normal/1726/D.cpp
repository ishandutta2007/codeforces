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
    #define dprint(...)
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

struct disjoin_set_union {
    int components;
    std::vector<int> parent, rank;

    disjoin_set_union(int n = 0) : components(n), parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int size() const {
        return rank.size();
    }

    void set_default() {
        components = size();
        std::fill(rank.begin(), rank.end(), 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) == 0 ? v : parent[v] = root(parent[v]);
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        components--;
        return true;
    }

    bool connected(int v, int u) {
        return root(v) == root(u);
    }
};

void solve(int test_num) {
    int n, m;
    cin >> n >> m;
    disjoin_set_union dsu(n);
    vector<pair<int, int>> edges(m);
    vector<int> extra;
    string ans(m, '0');
    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--, edges[i].second--;
        if (dsu.unite(edges[i].first, edges[i].second)) {
            ans[i] = '1';
            g[edges[i].first].emplace_back(edges[i].second, i);
            g[edges[i].second].emplace_back(edges[i].first, i);
        } else {
            extra.push_back(i);
        }
    }
    assert(len(extra) <= 3);
    assert(dsu.components == 1);

    if (len(extra) <= 2) {
        cout << ans << '\n';
        return;
    }
    
    {
        disjoin_set_union tmp_dsu(n);
        for (auto i : extra) {
            tmp_dsu.unite(edges[i].first, edges[i].second);
        }
        if (tmp_dsu.components == n - 3) {
            cout << ans << '\n';
            return;
        }
    }

    int from = edges[extra[0]].first, to = edges[extra[0]].second;
    ans[extra[0]] = '1';

    y_combinator([&](auto dfs, int v, int pid) -> void {
        if (v == to) {
            ans[pid] = '0';
            return;
        }
        for (auto &[u, id] : g[v]) {
            if (id == pid) continue;
            dfs(u, id);
        }
    })(from, -1);

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