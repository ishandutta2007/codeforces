#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
int n, q;
int dad[500005];
vector <int> child[500005];
long long w[500005];
long long a[500005];
int last[500005];
long long offset = 0;

vector <pair <int, pair <int, int> > > queries[500005];
long long t[2500005];
long long lazy[2500005];
long long ans[500005];

void build(int node, int l, int r) {
    if (l == r) {
        t[node] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(node * 2, l, m);
    build(node * 2 + 1, m + 1, r);
    t[node] = min(t[node * 2], t[node * 2 + 1]);
}

void unzip(int node, int l, int r) {
    t[node] += lazy[node];
    if (l != r) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void upd(int node, int l, int r, int u, int v, long long val) {
    unzip(node, l, r);
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        lazy[node] += val;
        unzip(node, l, r);
        return;
    }
    int m = l + r >> 1;
    upd(node * 2, l, m, u, v, val);
    upd(node * 2 + 1, m + 1, r, u, v, val);
    t[node] = min(t[node * 2], t[node * 2 + 1]);
}
long long get(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return inf;
    unzip(node, l, r);
    if (u <= l && r <= v) return t[node];
    int m = l + r >> 1;
    return min(get(node * 2, l, m, u, v),
               get(node * 2 + 1, m + 1, r, u, v));
}

void dfs(int u) {
    for (auto que: queries[u]) {
        ans[que.first] = get(1, 1, n, que.second.first, que.second.second) + offset;
    }
    for (auto v: child[u]) {
        offset += w[v];
        upd(1, 1, n, v, last[v], -2 * w[v]);
        dfs(v);
        offset -= w[v];
        upd(1, 1, n, v, last[v], +2 * w[v]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) last[i] = i;
    for (int i = 2; i <= n; ++i) {
        cin >> dad[i] >> w[i];
        a[i] = a[dad[i]] + w[i];
        child[dad[i]].push_back(i);
    }
    for (int i = n; i >= 1; --i) last[dad[i]] = max(last[dad[i]], last[i]);
    for (int i = 1; i <= n; ++i) if (last[i] != i) a[i] = inf;
    for (int i = 1; i <= q; ++i) {
        int u, l, r;
        cin >> u >> l >> r;
        queries[u].push_back(make_pair(i, make_pair(l, r)));
    }
    build(1, 1, n);
    dfs(1);
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    return 0;
}