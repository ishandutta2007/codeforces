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

void solve() {
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

    vector<int> que{0}, depth(n, n);
    depth[0] = 0;
    const int LG = __lg(n) + 1;
    vector parent(n, vector<int>(LG));

    for (int ptr = 0; ptr < len(que); ptr++) {
        int v = que[ptr];
        for (auto u : g[v])
            if (depth[u] == n) {
                depth[u] = depth[v] + 1;
                que.push_back(u);
                parent[u][0] = v;
                for (int i = 1; i < LG; i++)
                    parent[u][i] = parent[parent[u][i - 1]][i - 1];
            }
    }

    auto lca = [&](int v, int u) {
        if (depth[v] < depth[u])
            swap(v, u);

        for (int i = LG - 1; i >= 0; i--)
            if (depth[v] - (1 << i) >= depth[u])
                v = parent[v][i];

        for (int i = LG - 1; i >= 0; i--)
            if (parent[v][i] != parent[u][i]) {
                v = parent[v][i];
                u = parent[u][i];
            }

        return v == u ? v : parent[v][0];
    };

    auto dist = [&](int v, int u) {
        return depth[v] + depth[u] - 2 * depth[lca(v, u)];
    };

    vector<int> answer(n, depth[que.back()]);
    pair<int, int> diam{-1, -1};

    auto update_diam = [&](int v) {
        if (diam.first == -1) {
            diam = {v, v};
            return;
        }

        if (dist(v, diam.first) < dist(v, diam.second))
            swap(diam.first, diam.second);

        if (dist(v, diam.first) > dist(diam.first, diam.second))
            diam.second = v;
    };

    for (int i = n - 1; i; i--) {
        update_diam(que[i]);
        int x = depth[que[i - 1]] - (dist(diam.first, diam.second) + 1) / 2;
        if (x >= 1)
            answer[x - 1] = min(answer[x - 1], depth[que[i - 1]]);
    }

    for (int i = n - 2; i >= 0; i--)
        answer[i] = min(answer[i], answer[i + 1]);

    for (int i = 0; i < n; i++)
        cout << answer[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}