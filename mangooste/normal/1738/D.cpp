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
    #define dprint(...)
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

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    assert((count(all(a), 0) != 0) ^ (count(all(a), n + 1) != 0));

    bool reversed = false;
    if (count(all(a), 0)) {
        reversed = true;
        reverse(all(a));
        for (auto &x : a) x = n + 1 - x;
    }
    assert(count(all(a), 0) == 0);
    assert(count(all(a), n + 1) != 0);

    for (auto &x : a) x--;
    vector<vector<int>> g(n + 1);
    for (int val = 0; val < n; val++) {
        g[a[val]].push_back(val);
    }

    vector<bool> used(n + 1);
    vector<int> ans, color(n + 1);
    color[n] = 1;

    y_combinator([&](auto dfs, int v) -> void {
        assert(!used[v]);
        used[v] = true;
        sort(all(g[v]), [&](const int i, const int j) {
            return len(g[i]) < len(g[j]);
        });

        int not_zero = 0;
        for (auto u : g[v]) not_zero += len(g[u]) != 0;
        assert(not_zero <= 1);

        for (auto u : g[v]) {
            ans.push_back(u);
            color[u] = color[v] ^ 1;
            dfs(u);
        }
    })(n);

    int k = n - 1;
    while (color[k] == 1) k--;
    k++;

    assert(len(ans) == n);
    if (reversed) {
        k = n - k;
        for (auto &x : ans) x = n - 1 - x;
    }

    cout << k << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
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