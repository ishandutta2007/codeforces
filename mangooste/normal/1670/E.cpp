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
    int p;
    cin >> p;
    int n = 1 << p;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }

    vector<int> ans_v(n), ans_e(n - 1);
    ans_v[0] = n;
    int delta = 1;

    y_combinator([&](auto dfs, int v) -> void {
        for (auto &[u, i] : g[v]) {
            if (ans_v[v] >> p & 1) {
                ans_e[i] = n + delta;
                ans_v[u] = delta;
            } else {
                ans_e[i] = delta;
                ans_v[u] = n + delta;
            }
            delta++;

            g[u].erase(find(all(g[u]), pair{v, i}));
            dfs(u);
        }
    })(0);

    cout << "1\n";
    for (int i = 0; i < n; i++) {
        cout << ans_v[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << ans_e[i] << " \n"[i == n - 2];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}