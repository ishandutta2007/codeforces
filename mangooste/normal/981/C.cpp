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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

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

    int c = 0;
    for (int v = 1; v < n; v++) {
        if (len(g[v]) > len(g[c])) c = v;
    }

    bool ok = true;
    for (int v = 0; v < n; v++) {
        if (v == c) continue;
        ok &= len(g[v]) <= 2;
    }
    if (!ok) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    cout << len(g[c]) << '\n';
    for (auto v : g[c]) {
        g[v].erase(find(all(g[v]), c));
        int last = c;

        y_combinator([&](auto dfs, int v) -> void {
            last = v;
            assert(len(g[v]) <= 1);
            for (auto u : g[v]) {
                g[u].erase(find(all(g[u]), v));
                dfs(u);
            }
        })(v);

        assert(last != c);
        cout << c + 1 << ' ' << last + 1 << '\n';
    }
}