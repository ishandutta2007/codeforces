#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "First\n";
        for (int i = 1; i <= 2 * n; i++) {
            cout << i % n + 1 << " \n"[i == 2 * n];
        }
        return 0;
    }

    cout << "Second" << endl;
    vector<vector<int>> edges(n);
    for (int i = 1; i <= 2 * n; i++) {
        int p;
        cin >> p;
        edges[p - 1].push_back(i % (2 * n));
    }

    vector<vector<array<int, 3>>> g(n);
    vector<bool> used(n), ans(2 * n), used_edge(n);
    for (int i = 0; i < n; i++) {
        auto edge = edges[i];
        assert(len(edge) == 2);
        if (edge[0] % n == edge[1] % n) {
            used[edge[0] % n] = ans[edge[0]] = true;
            continue;
        }
        g[edge[0] % n].push_back({edge[1] % n, edge[0], i});
        g[edge[1] % n].push_back({edge[0] % n, edge[1], i});
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        int last = -1;

        y_combinator([&](auto dfs, int v) -> void {
            last = v;
            used[v] = true;
            for (auto [u, value, id] : g[v]) {
                if (used[u]) continue;
                assert(!used_edge[id]);
                used_edge[id] = true;
                ans[value] = true;
                dfs(u);
            }
        })(i);

        for (auto [u, value, id] : g[last]) {
            if (u == i && !used_edge[id]) {
                used_edge[id] = true;
                ans[value] = true;
            }
        }
    }

    assert(count(all(ans), true) == n);
    ll sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (ans[i]) {
            sum += i;
        }
    }
    if (sum % (2 * n) == 0) {
        for (int i = 0; i < 2 * n; i++) {
            if (ans[i]) cout << (i == 0 ? 2 * n : i) << ' ';
        }
    } else {
        assert(sum % (2 * n) == n);
        for (int i = 0; i < 2 * n; i++) {
            if (!ans[i]) cout << (i == 0 ? 2 * n : i) << ' ';
        }
    }
    cout << '\n';
}