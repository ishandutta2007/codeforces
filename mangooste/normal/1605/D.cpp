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
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector<int> color(n);

    y_combinator([&](auto dfs, int v) -> void {
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            color[u] = color[v] ^ 1;
            dfs(u);
        }
    })(0);

    if (count(all(color), 1) * 2 < n) {
        for (auto &x : color) x ^= 1;
    }
    const int LG = __lg(n);
    vector<vector<int>> group(LG + 1);
    for (int i = 1; i <= n; i++) {
        group[__lg(i)].push_back(i);
    }

    array<vector<int>, 2> pos;
    for (int i = 0; i < n; i++) pos[color[i]].push_back(i);

    for (int i = 0; i < LG; i++) assert(len(group[i]) == (1 << i));
    assert(len(group[LG]) <= len(pos[1]));

    int extra = len(pos[1]) - len(group[LG]);
    vector<int> p(n);

    auto run = [&](int bit, int rot) {
        while (!group[bit].empty()) {
            assert(!pos[rot].empty());
            p[pos[rot].back()] = group[bit].back();
            pos[rot].pop_back();
            group[bit].pop_back();
        }
    };

    run(LG, 1);
    for (int i = 0; i < LG; i++) run(i, extra >> i & 1);

    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
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