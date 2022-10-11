#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

struct segtree {
    int n;
    vec<int> tree;

    segtree() {}
    segtree(int n) : n(n), tree(2 * n) {}

    inline void update(int pos, int delta) {
        pos += n;
        tree[pos] += delta;
        for (pos /= 2; pos; pos /= 2)
            tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }

    inline int get_sum(int l, int r) {
        int sum = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                sum += tree[l++];
            if (r % 2)
                sum += tree[--r];
        }
        return sum;
    }
};

int n, m, lg;
vec<vec<int>> g;
vec<vec<int>> par;
int timer;
vec<int> tin, tout;
vec<vec<pr<int>>> hard;
vec<vec<int>> single;
vec<int> st;
segtree tree;
ll ans;

void init(int v) {
    if (v)
        g[v].erase(find(all(g[v]), par[0][v]));
    tin[v] = timer++;
    for (int i = 0; i < lg - 1; i++)
        par[i + 1][v] = par[i][par[i][v]];
    for (auto u : g[v]) {
        par[0][u] = v;
        init(u);
    }
    tout[v] = timer;
}

inline bool is_par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

inline int lca(int v, int u) {
    if (is_par(v, u))
        return v;
    for (int i = lg - 1; i >= 0; i--)
        if (!is_par(par[i][v], u))
            v = par[i][v];
    return par[0][v];
}

inline int id(int v, int t) {
    int l = 0, r = len(g[v]);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (tin[g[v][mid]] > t)
            r = mid;
        else
            l = mid;
    }
    return l;
}

void solve(int v) {
    for (auto u : g[v])
        solve(u);
    for (auto u : single[v])
        if (u != v)
            tree.update(tin[u], -1);
    for (auto [a, b] : hard[v]) {
        tree.update(tin[a], -1);
        tree.update(tin[b], -1);
    }

    for (auto &u : single[v])
        if (u == v)
            u = -1;
        else
            u = id(v, tin[u]);
    for (auto &[a, b] : hard[v]) {
        a = id(v, tin[a]);
        b = id(v, tin[b]);
    }

    tree.update(tin[v], st[v]);
    int sz = len(g[v]);
    vec<int> cnt(sz);
    for (auto u : single[v])
        if (u != -1)
            cnt[u]++;
    for (auto [a, b] : hard[v]) {
        cnt[a]++;
        cnt[b]++;
    }

    vec<int> cnt_hard(sz);
    for (auto [a, b] : hard[v]) {
        cnt_hard[a]++;
        cnt_hard[b]++;
    }

    int segsum = tree.get_sum(tin[v], tout[v]);
    int tot = len(single[v]) + len(hard[v]);
    for (auto u : single[v]) {
        if (u == -1) {
            ans += tot - 1;
            ans += len(hard[v]);
            ans += 2 * segsum;
            continue;
        }
        ans += tot - cnt[u];
        ans += len(hard[v]) - cnt_hard[u];
        ans += 2 * (segsum - tree.get_sum(tin[g[v][u]], tout[g[v][u]]));
    }
    for (auto [a, b] : hard[v])
        ans += 2 * (segsum - tree.get_sum(tin[g[v][a]], tout[g[v][a]]) - tree.get_sum(tin[g[v][b]], tout[g[v][b]]));

    for (auto u : single[v])
        if (u != -1)
            cnt[u]--;

    sz = len(hard[v]);
    if (sz <= 1)
        return;
    ans += 1ll * sz * (sz - 1);
    map<pr<int>, int> mp;
    for (auto [a, b] : hard[v]) {
        ans -= cnt[a] - 1;
        ans -= cnt[b] - 1;
        if (a > b)
            swap(a, b);
        mp[{a, b}]++;
    }

    for (auto [_, cnt] : mp)
        ans += 1ll * cnt * (cnt - 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    lg = __lg(n) + 1;
    par.resize(lg, vec<int>(n));
    tin.resize(n);
    tout.resize(n);
    init(0);

    hard.resize(n);
    single.resize(n);
    st.resize(n);

    cin >> m;
    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        int w = lca(v, u);
        if (tin[v] > tin[u])
            swap(v, u);

        if (is_par(v, u)) {
            if (u != w)
                st[u]++;
            single[v].push_back(u);
        } else {
            hard[w].emplace_back(v, u);
            st[v]++;
            st[u]++;
        }
    }

    tree = segtree(n);
    solve(0);
    cout << ans / 2 << '\n';
}