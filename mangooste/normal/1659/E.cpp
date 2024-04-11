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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto &[v, u, w] : edges) {
        cin >> v >> u >> w;
        v--, u--;
    }

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (auto &[v, u] : queries) {
        cin >> v >> u;
        v--, u--;
    }

    vector<int> ans(q, 2);
    for (int bit = 0; bit < 30; bit++) {
        disjoin_set_union dsu(n);
        for (auto &[v, u, w] : edges) {
            if (w >> bit & 1) dsu.unite(v, u);
        }

        for (int i = 0; i < q; i++) {
            auto [v, u] = queries[i];
            if (dsu.connected(v, u)) ans[i] = 0;
        }
        if (bit == 0) continue;

        vector<bool> good(n);
        for (auto &[v, u, w] : edges) {
            if (w % 2 == 0) good[dsu.root(v)] = good[dsu.root(u)] = true;
        }
        for (int i = 0; i < q; i++) {
            if (ans[i] == 0) continue;
            auto [v, u] = queries[i];
            if (good[dsu.root(v)]) ans[i] = 1;
        }
    }

    for (auto x : ans) cout << x << '\n';
}