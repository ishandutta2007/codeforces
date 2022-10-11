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
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int root = min_element(all(a)) - a.begin();

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        if (a[v] > a[u])
            swap(v, u);

        g[v].push_back(u);
    }

    ll answer = accumulate(all(a), 0ll) - a[root];
    int lg = __lg(n) + 2;
    vector<vector<int>> parent(n, vector<int>(lg, root));

    y_combinator([&](auto dfs, int v) -> void {
        for (int i = 1; i < lg; i++)
            parent[v][i] = parent[parent[v][i - 1]][i - 1];

        for (auto u : g[v]) {
            parent[u][0] = v;
            dfs(u);
        }

        if (v == root)
            return;

        ll best = LLONG_MAX;
        for (int i = 0; i < lg; i++)
            best = min(best, 1ll * (i + 1) * a[parent[v][i]]);

        answer += best;
    })(root);

    cout << answer << '\n';
}