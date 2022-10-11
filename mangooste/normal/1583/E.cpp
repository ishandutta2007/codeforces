#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun_;

    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

struct disjoin_set_union {
    int components;
    std::vector<int> parent;
    std::vector<int> rank;

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

    vector<vector<int>> g(n);
    disjoin_set_union dsu(n);

    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        if (dsu.unite(v, u)) {
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }
    assert(dsu.components == 1);

    int timer = 0;
    vector<int> tin(n);
    vector<int> tout(n);
    vector<int> parent(n);

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            parent[u] = v;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    auto is_parent = [&](int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    };

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);

    vector<int> dp(n);
    for (auto &[from, to] : queries) {
        cin >> from >> to;
        from--, to--;

        dp[from] ^= 1;
        dp[to] ^= 1;
    }

    int answer = 0;

    y_combinator([&](auto dfs, int v) -> int {
        int have = 0;
        for (auto u : g[v]) {
            int cur = dfs(u);
            if (have && cur) {
                have = 0;
                answer++;
            } else if (cur) {
                have = 1;
            }
            dp[v] ^= dp[u];
        }

        if (v == 0) {
            answer += have;
            return 0;
        }

        if (!(dp[v] ^ have))
            return have;

        if (have) {
            answer++;
            return 0;
        }

        return 1;
    })(0);

    if (answer != 0) {
        cout << "NO\n" << answer << '\n';
        return 0;
    }

    cout << "YES\n";
    for (auto [from, to] : queries) {
        vector<int> way;
        while (!is_parent(from, to)) {
            way.push_back(from);
            from = parent[from];
        }
        way.push_back(from);

        vector<int> way2;
        while (to != from) {
            way2.push_back(to);
            to = parent[to];
        }

        reverse(all(way2));
        cout << len(way) + len(way2) << '\n';
        for (auto x : way)
            cout << x + 1 << ' ';

        for (auto x : way2)
            cout << x + 1 << ' ';

        cout << '\n';
    }
}