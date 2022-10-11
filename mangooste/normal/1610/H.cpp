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

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = 0) : bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = value * (i & -i);
    }

    void add(int pos, T delta) {
        for (pos++; pos < int(bit.size()); pos += pos & -pos)
            bit[pos] += delta;
    }

    T query(int pref) {
        T sum = 0;
        for (pref++; pref > 0; pref -= pref & -pref)
            sum += bit[pref];

        return sum;
    }

    T query(int l, int r) {
        if (r >= int(bit.size()))
            r = int(bit.size()) - 1;

        if (l < 0)
            l = 0;

        if (r <= l)
            return 0;

        return query(r - 1) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> p(n), pp(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pp[i] = p[i];
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }

    vector<int> tin(n), tout(n), dep(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        if (dep[p[v]] - dep[pp[p[v]]] == dep[pp[p[v]]] - dep[pp[pp[p[v]]]]) {
            pp[v] = pp[pp[p[v]]];
        }
        tin[v] = timer++;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dep[u] = dep[v] + 1;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    auto is_ancestor = [&](int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    };

    auto pre_ancestor = [&](int v, int u) {
        while (true) {
            if (!is_ancestor(pp[v], u)) {
                v = pp[v];
            } else if (!is_ancestor(p[v], u)) {
                v = p[v];
            } else {
                return v;
            }
        }
        assert(false);
    };

    auto get_path = [&](int v, int u) {
        if (tin[v] > tin[u]) swap(v, u);
        array<pair<int, int>, 3> segs;
        segs.fill({0, 0});
        if (is_ancestor(v, u)) {
            int x = pre_ancestor(u, v);
            segs[0] = {tin[x], tin[u]};
            segs[1] = {tout[u], tout[x]};
            return segs;
        }

        segs[0] = {0, tin[v]};
        segs[1] = {tout[v], tin[u]};
        segs[2] = {tout[u], n};
        return segs;
    };

    vector<array<pair<int, int>, 3>> paths(m);
    vector<int> x(m), y(m);
    vector<vector<pair<int, int>>> ends(n);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        paths[i] = get_path(x[i], y[i]);

        ends[x[i]].emplace_back(y[i], i);
        ends[y[i]].emplace_back(x[i], i);

        int tot = 0;
        for (auto [l, r] : paths[i]) {
            tot += r - l;
        }
        if (tot == 0) {
            cout << "-1\n";
            return 0;
        }
    }

    binary_indexed_tree<int> bit(n);
    vector<int> dp(n);
    vector<set<int>> st(n);

    y_combinator([&](auto dfs, int v) -> void {
        for (auto u : g[v]) {
            dfs(u);
            dp[v] += dp[u];
        }

        for (auto [u, id] : ends[v]) {
            if (is_ancestor(v, u)) {
                bool any = false;
                for (auto [l, r] : paths[id]) {
                    any |= bit.query(l, r);
                }
                if (any) continue;
                dp[v]++;
                int x = pre_ancestor(u, v);
                st[v].insert(x);
                bit.add(tin[x], 1);
            }
        }
    })(0);

    int ans = n;

    y_combinator([&](auto dfs, int v) -> void {
        ans = min(ans, dp[v] + 1);

        for (auto u : g[v]) {
            int old_dp_v = dp[v], old_dp_u = dp[u];
            dp[v] -= dp[u];
            if (st[v].count(u)) {
                bit.add(tin[u], -1);
                dp[v]--;
            }

            dp[u] += dp[v];
            bool changed = false;
            for (auto [w, id] : ends[u]) {
                if (!is_ancestor(u, w)) {
                    bool any = false;
                    for (auto [l, r] : paths[id]) {
                        any |= bit.query(l, r);
                    }
                    if (any) continue;

                    assert(!changed);
                    changed = true;
                    bit.add(tin[v], 1);
                    dp[u]++;
                }
            }

            dfs(u);

            if (changed) {
                bit.add(tin[v], -1);
            }
            if (st[v].count(u)) {
                bit.add(tin[u], 1);
            }
            dp[u] = old_dp_u;
            dp[v] = old_dp_v;
        }
    })(0);

    cout << ans << '\n';
}