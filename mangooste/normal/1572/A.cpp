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

    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        while (sz--) {
            int who;
            cin >> who;
            g[who - 1].push_back(i);
        }
    }

    vector<int> used(n);
    vector<int> order;
    bool ok = true;

    for (int i = 0; i < n && ok; i++)
        if (used[i] == 0)
            y_combinator([&](auto dfs, int v) -> void {
                used[v] = 1;
                for (auto u : g[v])
                    if (used[u] == 0)
                        dfs(u);
                    else if (used[u] == 1)
                        ok = false;

                order.push_back(v);
                used[v] = 2;
            })(i);

    if (!ok) {
        cout << "-1\n";
        return;
    }

    reverse(all(order));
    vector<int> dp(n, 1);

    for (auto i : order)
        for (auto j : g[i])
            dp[j] = max(dp[j], dp[i] + (i > j));

    cout << *max_element(all(dp)) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}