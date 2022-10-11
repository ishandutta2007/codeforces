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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> banned;
    banned.reserve(2 * m);
    vector<array<int, 4>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--, edges[i][2]--;
        edges[i][3] = i;
        banned.emplace_back(edges[i][1], edges[i][2]);
        banned.emplace_back(edges[i][2], edges[i][1]);
    }
    sort(all(edges));
    sort(all(banned));

    struct bamboo_disjoin_set_union {
        vector<int> parent, rank, first, last, nxt, nxt_e;

        bamboo_disjoin_set_union(int n) : parent(n), rank(n, 1), first(n), last(n), nxt(n, -1), nxt_e(n, -1) {
            iota(all(parent), 0);
            first = last = parent;
        }

        int root(int v) {
            return parent[v] == v ? v : parent[v] = root(parent[v]);
        }

        void unite(int v, int u, int cost) {
            v = root(v);
            u = root(u);
            if (v == u)
                return;

            if (rank[v] < rank[u])
                swap(v, u);

            parent[u] = v;
            rank[v] += rank[u];
            nxt[last[v]] = first[u];
            nxt_e[last[v]] = cost;
            last[v] = last[u];
        }

        pair<vector<int>, vector<int>> get_path() {
            vector<int> path, path_e;
            path.reserve(len(parent));
            path_e.reserve(len(parent) - 1);
            path.push_back(first[root(0)]);

            while (true) {
                int cur = nxt[path.back()];
                if (cur == -1)
                    break;

                path_e.push_back(nxt_e[path.back()]);
                path.push_back(cur);
            }
            return {path, path_e};
        }
    } bamboo_dsu(n);

    for (auto &[cost, v, u, id] : edges)
        bamboo_dsu.unite(v, u, cost);

    auto [path, path_e] = bamboo_dsu.get_path();
    disjoin_set_union dsu(n);

    vector<vector<pair<int, int>>> g(n);

    auto add_edge = [&](int v, int u, int cost) {
        g[v].emplace_back(u, cost);
        g[u].emplace_back(v, cost);
    };

    constexpr int INF = 1e9 + 228;
    vector<int> prev(n), prev_max(n);
    vector<array<int, 3>> min_out(n);

    while (dsu.components != 1) {
        fill(all(min_out), array{INF, -1, -1});
        for (int rot = 0; rot < 2; rot++, reverse(all(path)), reverse(all(path_e))) {
            fill(all(prev), -1);
            fill(all(prev_max), -INF);

            for (int i = 1; i < n; i++) {
                prev[i] = dsu.root(path[i]) == dsu.root(path[i - 1]) ? prev[i - 1] : i - 1;
                prev_max[i] = dsu.root(path[i]) == dsu.root(path[i - 1]) ? max(path_e[i - 1], prev_max[i - 1]) : path_e[i - 1];

                for (int j = i - 1, cur_max = path_e[i - 1]; j >= 0;)
                    if (dsu.root(path[i]) == dsu.root(path[j])) {
                        cur_max = max(cur_max, prev_max[j]);
                        j = prev[j];
                    } else if (!binary_search(all(banned), pair{path[i], path[j]})) {
                        min_out[dsu.root(path[i])] = min(min_out[dsu.root(path[i])], array{cur_max, path[i], path[j]});
                        break;
                    } else {
                        if (j == 0)
                            break;

                        cur_max = max(cur_max, path_e[j - 1]);
                        j--;
                    }
            }
        }

        for (int i = 0; i < n; i++)
            if (dsu.root(i) == i && dsu.unite(min_out[i][1], min_out[i][2]))
                add_edge(min_out[i][1], min_out[i][2], min_out[i][0]);
    }

    const int LG = __lg(n) + 1;
    vector parent(n, vector<int>(LG)), mx(n, vector<int>(LG, -INF));
    vector<int> tin(n), tout(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        for (int i = 1; i < LG; i++) {
            parent[v][i] = parent[parent[v][i - 1]][i - 1];
            mx[v][i] = max(mx[v][i - 1], mx[parent[v][i - 1]][i - 1]);
        }

        tin[v] = timer++;
        for (auto &[u, c] : g[v]) {
            g[u].erase(find(all(g[u]), pair{v, c}));
            parent[u][0] = v;
            mx[u][0] = c;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    auto is_ancestor = [&](int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    };

    auto get_max = [&](int v, int u) {
        if (is_ancestor(v, u))
            return -INF;

        int res = -INF;
        for (int i = LG - 1; i >= 0; i--)
            if (!is_ancestor(parent[v][i], u)) {
                res = max(res, mx[v][i]);
                v = parent[v][i];
            }

        return max(res, mx[v][0]);
    };

    vector<int> answer(m);
    for (auto &[cost, v, u, id] : edges)
        answer[id] = max(get_max(v, u), get_max(u, v));

    for (int i = 0; i < m; i++)
        cout << answer[i] << " \n"[i == m - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}