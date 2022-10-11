#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
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

    vector<char> leaf(n);
    vector<int> d;
    int leafs = 0;

    y_combinator([&](auto dfs, int v) -> void {
        int count = 0;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            count += leaf[u];
        }

        if (v == 0) {
            leafs = count;
            return;
        }

        if (count == 0)
            leaf[v] = 1;
        else
            d.push_back(count);
    })(0);

    cout << leafs + accumulate(all(d), 0) - (len(d) - 1) - (leafs != 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}