#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define ends dont_use_ends

const ll INF = 1e18;

struct segtree {
    int n;
    vector<ll> tree, mod;

    segtree() {}
    segtree(int n) : n(n), tree(4 * n, INF), mod(4 * n) {}

    inline void push(int v, int vl, int vr) {
        if (!mod[v])
            return;
        tree[v] += mod[v];
        if (vr - vl > 1) {
            mod[2 * v] += mod[v];
            mod[2 * v + 1] += mod[v];
        }
        mod[v] = 0;
    }

    inline void add(int l, int r, ll delta) {
        update(1, 0, n, l, r, delta);
    }

    void update(int v, int vl, int vr, int l, int r, ll delta) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return;
        if (l <= vl && vr <= r) {
            mod[v] += delta;
            return;
        }
        int vm = (vl + vr) / 2;
        update(2 * v, vl, vm, l, r, delta);
        update(2 * v + 1, vm, vr, l, r, delta);
        push(2 * v, vl, vm);
        push(2 * v + 1, vm, vr);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }

    inline ll get_min(int l, int r) {
        return get(1, 0, n, l, r);
    }

    ll get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return INF;
        if (l <= vl && vr <= r)
            return tree[v];
        int vm = (vl + vr) / 2;
        return min(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
};

const int LG = 19;

int n, l;
ll s;
vector<vector<int>> g;
int timer;
vector<int> p, tin, tout;
vector<vector<pair<int, ll>>> to;
vector<vector<int>> ends;
segtree tree;
vector<ll> dp;

void init(int v) {
    tin[v] = timer++;
    for (int level = 0; level < LG - 1; level++) {
        to[level + 1][v].first = to[level][to[level][v].first].first;
        to[level + 1][v].second = to[level][to[level][v].first].second + to[level][v].second;
    }
    for (auto u : g[v]) {
        to[0][u] = {v, p[v]};
        init(u);
    }
    tout[v] = timer;
}

void dfs(int v) {
    ll sum = 0;
    for (auto u : g[v]) {
        dfs(u);
        sum += dp[u];
    }
    dp[v] = min(sum, tree.get_min(tin[v], tout[v]) + sum) + 1;
    tree.add(tin[v], tin[v] + 1, -tree.get_min(tin[v], tin[v] + 1));
    for (auto u : ends[v])
        tree.add(tin[u], tin[u] + 1, INF);
    tree.add(tin[v], tout[v], sum - dp[v]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> l >> s;
    p.resize(n);
    for (auto &x : p) {
        cin >> x;
        if (x > s) {
            cout << "-1\n";
            return 0;
        }
    }
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    to.resize(LG, vector<pair<int, ll>>(n));
    tin.resize(n);
    tout.resize(n);
    init(0);

    ends.resize(n);
    for (int i = 0; i < n; i++) {
        ll left_sum = s - p[i];
        int left_dist = l - 1;
        int where = i;
        for (int j = LG - 1; j >= 0; j--)
            if (left_sum >= to[j][where].second && left_dist >= (1 << j)) {
                left_sum -= to[j][where].second;
                left_dist -= (1 << j);
                where = to[j][where].first;
            }
        ends[where].push_back(i);
    }

    tree = segtree(2 * n);
    dp.resize(n);
    dfs(0);
    cout << dp[0] << '\n';
}