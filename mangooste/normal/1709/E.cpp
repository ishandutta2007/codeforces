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
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    // (v, u) is bad if pref[v] ^ pref[u] ^ a[lca(v, u)] = 0
    vector<int> pref(n);
    int ans = 0;

    y_combinator([&](auto dfs, int v) -> set<int> {
        pref[v] ^= a[v];
        if (g[v].empty()) return {pref[v]};

        bool bad = false;
        set<int> st;
        st.insert(pref[v]);

        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            pref[u] = pref[v];
            auto cur = dfs(u);
            if (len(st) < len(cur)) swap(st, cur);
            for (auto x : cur) bad |= st.count(x ^ a[v]);
            for (auto x : cur) st.insert(x);
            set<int>().swap(cur);
        }

        if (bad) {
            ans++;
            return {};
        }
        return st;
    })(0);

    cout << ans << '\n';
}