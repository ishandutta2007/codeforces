#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
    ll ans = 1;
    while (b) {
        while (!(b & 1))
            b >>= 1, a = (a * a) % MOD;
        ans = (ans * a) % MOD;
        --b;
    }
    return ans;
}
const int MAXN = 100100;
int sz[MAXN];
int was[MAXN];
vector<tuple<int, ll, int> > eds[MAXN];
vector<tuple<int, int, ll, int> > ed;
int SZ;
int ad;
int rmq[MAXN * 4 * 3];
int n;
int cc[MAXN * 3];
vector<int> vv;

void build(int v, int tl, int tr) {
    if (tl + 1 == tr) {
        rmq[v] = cc[tl];
        return;
    }
    int m = (tl + tr) >> 1;
    build(v * 2 + 1, tl, m);
    build(v * 2 + 2, m, tr);
    rmq[v] = rmq[v * 2 + 1] + rmq[v * 2 + 2];
}

void add(int v, int tl, int tr, int x, int d) {
    rmq[v] += d;
    if (tl + 1 == tr)
        return;
    int m = (tl + tr) >> 1;
    if (x < m)
        add(v * 2 + 1, tl, m, x, d);
    else
        add(v * 2 + 2, m, tr, x, d);
}

int get(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l)
        return 0;
    if (l <= tl && tr <= r)
        return rmq[v];
    int m = (tl + tr) >> 1;
    return get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m, tr, l, r);
}


ll gans = 1;

void dfs2(int v, int p) {
    vv.push_back(v);
    sz[v] = 1;
    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (u == p || was[u])
            continue;
        dfs2(u, v);
        sz[v] += sz[u];
    }
}

void dfs3(int v, int p, int c1) {
    ++cc[ad + c1];
    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (u == p || was[u])
            continue;
        dfs3(u, v, c1 + get<2>(e));
    }
}

void dfs4(int v, int p, int c1, int d) {
    add(0, 0, SZ, ad + c1, d);
    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (u == p || was[u])
            continue;
        dfs4(u, v, c1 + get<2>(e), d);
    }
}

void dfs5(int v, int p, int c1, ll c2) {
    if (ad > c1) {
        int k = get(0, 0, SZ, 0, ad - c1);
        gans = (gans * pw(c2, k)) % MOD;
    }
    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (u == p || was[u])
            continue;
        dfs5(u, v, c1 + get<2>(e), (c2 * get<1>(e)) % MOD);
    }
}

void run(int v) {
    vv.clear();
    dfs2(v, -1);
    int bst = -1;
    for (int u: vv) {
        if (sz[u] * 2 >= vv.size() && (bst == -1 || sz[u] < sz[bst]))
            bst = u;
    }
    v = bst;
    was[v] = 1;
    ad = vv.size() + 1;
    SZ = 3 * (vv.size() + 1);
    memset(cc, 0, sizeof(cc[0]) * SZ);
    cc[ad] += 1;
    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (!was[u])
            dfs3(u, v, 0 + get<2>(e));
    }
    build(0, 0, SZ);
    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (was[u])
            continue;
        int w = get<2>(e);
        ll c = get<1>(e);
        dfs4(u, v, w, -1);
        dfs5(u, v, w, c);

        dfs4(u, v, w, 1);
    }

    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (!was[u])
            run(u);
    }
}


ll solve() {
    memset(was, 0, sizeof(was));
    gans = 1;
    run(0);
    return gans;
}






ll ans = 1;

void dfs1(int v) {
    sz[v] = 1;
    was[v] = 1;
    for (auto e: eds[v]) {
        int u = get<0>(e);
        if (was[u])
            continue;
        dfs1(u);
        sz[v] += sz[u];
        ans = (ans * pw(get<1>(e), (ll)sz[u] * (n - sz[u]))) % MOD;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        ll x;
        int c;
        scanf("%d%d%lld%d", &a, &b, &x, &c);
        --a, --b;
        ed.push_back(make_tuple(a, b, x, c));
    }
    for (int i = 0; i < n; ++i)
        eds[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        ll x;
        int c;
        tie(a, b, x, c) = ed[i];
        if (c == 0)
            c = 2;
        else
            c = -1;
        eds[a].push_back(make_tuple(b, x, c));
        eds[b].push_back(make_tuple(a, x, c));
    }
    ll x1 = solve();
    for (int i = 0; i < n; ++i)
        eds[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        ll x;
        int c;
        tie(a, b, x, c) = ed[i];
        if (c == 1)
            c = 2;
        else
            c = -1;
        eds[a].push_back(make_tuple(b, x, c));
        eds[b].push_back(make_tuple(a, x, c));
    }
    ll x2 = solve();
    x1 = pw(x1, MOD - 2);
    x2 = pw(x2, MOD - 2);
    memset(was, 0, sizeof(was));
    dfs1(0);
    ans = (ans * x1) % MOD;
    ans = (ans * x2) % MOD;
    cout << ans << "\n";
    return 0;
}