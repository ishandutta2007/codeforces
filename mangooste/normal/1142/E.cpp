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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> rev_g(n);

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        rev_g[u].push_back(v);
    }

    vector<int> order;
    vector<bool> used(n);
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            y_combinator([&](auto dfs, int v) -> void {
                used[v] = true;
                for (auto u : g[v])
                    if (!used[u])
                        dfs(u);

                order.push_back(v);
            })(i);
        }

    reverse(all(order));
    fill(all(used), false);

    vector<vector<int>> components;
    vector<int> where(n);

    for (auto i : order)
        if (!used[i]) {
            components.push_back({});

            y_combinator([&](auto dfs, int v) -> void {
                used[v] = true;
                where[v] = len(components) - 1;
                for (auto u : rev_g[v])
                    if (!used[u])
                        dfs(u);

                components.back().push_back(v);
            })(i);
        }

    int sz = len(components);
    vector<vector<int>> dag(sz);
    for (int i = 0; i < n; i++)
        for (auto j : g[i])
            if (where[i] != where[j])
                dag[where[i]].push_back(where[j]);

    for (int i = 0; i < sz; i++) {
        sort(all(dag[i]));
        dag[i].resize(unique(all(dag[i])) - dag[i].begin());
    }

    vector<int> in_degree(sz);
    for (int i = 0; i < sz; i++)
        for (auto j : dag[i])
            in_degree[j]++;

    queue<int> que;
    for (int i = 0; i < sz; i++)
        if (in_degree[i] == 0)
            que.push(i);

    int total_queries = 0;

    auto query = [&](int v, int u) {
        assert(++total_queries <= 2 * n);
        assert(v != u);

        cout << "? " << v + 1 << ' ' << u + 1 << endl;
        int res;
        cin >> res;
        return res;
    };

    auto solve = [&](int a, int b) {
        int pos_a = 0;
        int pos_b = 0;

        while (true) {
            if (pos_b == len(components[b]))
                return components[a][pos_a];

            if (!query(components[a][pos_a], components[b][pos_b])) {
                swap(a, b);
                swap(pos_a, pos_b);
            }
            pos_b++;
        }

        assert(false);
    };

    while (len(que) != 1) {
        int a = que.front();
        que.pop();
        int b = que.front();
        que.pop();

        auto who = solve(a, b);
        if (where[who] == b)
            swap(a, b);

        rotate(components[a].begin(), find(all(components[a]), who), components[a].end());
        que.push(a);
        for (auto x : dag[b])
            if (--in_degree[x] == 0)
                que.push(x);
    }

    cout << "! " << components[que.front()][0] + 1 << endl;
}