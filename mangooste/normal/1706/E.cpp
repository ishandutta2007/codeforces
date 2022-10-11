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

template<typename T, typename merge_t>
struct sparse_table {
    std::vector<std::vector<T>> sparse;
    const merge_t merge;

    sparse_table(const merge_t &merge) : merge(merge) {}

    sparse_table(const std::vector<T> &a, const merge_t &merge) : merge(merge) {
        if (a.empty())
            return;

        const int n = int(a.size()), lg = std::__lg(n);
        sparse.reserve(lg + 1);
        sparse.push_back(a);

        for (int level = 1; level <= lg; level++) {
            sparse.push_back(std::vector<T>(n - (1 << level) + 1));
            for (int i = 0; i < int(sparse[level].size()); i++)
                sparse[level][i] = merge(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
        }
    }

    T query(int l, int r) const {
        assert(l < r);
        const int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

void solve(int test_num) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> edges(m);
    for (auto &[v, u] : edges) {
        cin >> v >> u;
        v--, u--;
    }

    vector<set<int>> comps(n);
    vector<int> par(n);
    iota(all(par), 0);
    for (int i = 0; i < n; i++) comps[i] = {i};

    auto root = y_combinator([&](auto root, int v) -> int {
        return par[v] == v ? v : par[v] = root(par[v]);
    });

    vector<int> when(n - 1, -1);
    for (int i = 0; i < m; i++) {
        auto [v, u] = edges[i];
        v = root(v), u = root(u);
        if (v == u) continue;
        if (len(comps[v]) < len(comps[u])) swap(v, u);

        while (!comps[u].empty()) {
            int w = *comps[u].begin();
            comps[u].erase(comps[u].begin());
            if (w && when[w - 1] == -1 && comps[v].count(w - 1)) {
                when[w - 1] = i;
            }
            if (w + 1 < n && when[w] == -1 && comps[v].count(w + 1)) {
                when[w] = i;
            }
            comps[v].insert(w);
        }
        set<int>().swap(comps[u]);
        par[u] = v;
    }
    for (auto &x : when) assert(x != -1);

    auto merge = [&](int a, int b) {
        return max(a, b);
    };
    sparse_table<int, decltype(merge)> sparse(when, merge);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) {
            cout << "0\n";
        } else {
            cout << sparse.query(l, r) + 1 << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}