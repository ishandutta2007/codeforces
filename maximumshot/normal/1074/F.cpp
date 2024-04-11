#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

struct RangeTree {
    int n = 0; // 1 .. n
    vec< int > pu, mx, cn;

    void f(int v, int x) {
        pu[v] += x;
        mx[v] += x;
    }

    void push(int v)  {
        f(v << 1, pu[v]);
        f(v << 1 | 1, pu[v]);
        pu[v] = 0;
    }

    void merge(int v) {
        mx[v] = mx[v << 1];
        cn[v] = cn[v << 1];

        if(mx[v] < mx[v << 1 | 1]) {
            mx[v] = mx[v << 1 | 1];
            cn[v] = cn[v << 1 | 1];
        }else if(mx[v] == mx[v << 1 | 1]) {
            cn[v] += cn[v << 1 | 1];
        }
    }

    void build(int v, int tl, int tr) {
        if(tl == tr) {
            pu[v] = 0;
            mx[v] = 0;
            cn[v] = 1;
        }else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
            merge(v);
        }
    }

    RangeTree() = default;

    RangeTree(int _n): n(_n)
    {
        pu.resize(n << 2);
        mx.reserve(n << 2);
        cn.resize(n << 2);
        build(1, 1, n);
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if(l <= tl && tr <= r) {
            f(v, x);
        }else {
            int tm = (tl + tr) >> 1;
            push(v);
            if(l <= tm) update(v << 1, tl, tm, l, r, x);
            if(r > tm)  update(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    int get(int x) const { return mx[1] == x ? cn[1] : 0; }
};

const int N = 2e5 + 5;
const int LOG = 21;

int n, q;
vec< int > g[N];
int tin[N], tout[N];
int hh[N];
int pp[LOG][N];
int timer = 1;
RangeTree rt;

int get_lca(int u, int v) {
    if(hh[u] < hh[v]) swap(u, v);
    for(int j = LOG - 1;j >= 0;j--) {
        int pu = pp[j][u];
        if(pu == -1 || hh[pu] < hh[v]) continue;
        u = pu;
    }
    for(int j = LOG - 1;j >= 0;j--) {
        int pu = pp[j][u];
        int pv = pp[j][v];
        if(pu == -1 || pv == -1 || pu == pv) continue;
        u = pu;
        v = pv;
    }
    if(u != v) u = pp[0][u];
    return u;
}

void dfs(int v, int par = -1) {
    tin[v] = timer++;
    hh[v] = par == -1 ? 0 : hh[par] + 1;
    pp[0][v] = par;
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
    }
    tout[v] = timer;
}

int jump(int P, int S) {
    for(int j = LOG - 1;j >= 0;j--) {
        int _S = pp[j][S];
        if(_S == -1 || hh[_S] <= hh[P]) continue;
        S = _S;
    }
    return S;
}

void query(int u, int v, int t) {
    if(hh[u] > hh[v]) swap(u, v);
    int w = get_lca(u, v);

    rt.update(tin[v], tout[v] - 1, t);

    if(u != w) {
        rt.update(tin[u], tout[u] - 1, t);
    }else {
        u = jump(u, v);
        rt.update(1, n, t);
        rt.update(tin[u], tout[u] - 1, -t);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int j = 0;j < LOG;j++) {
        for(int v = 1;v <= n;v++) {
            pp[j][v] = -1;
        }
    }

    dfs(1);

    for(int j = 1;j < LOG;j++) {
        for(int v = 1;v <= n;v++) {
            int pv = pp[j - 1][v];
            if(pv == -1) {
                pp[j][v] = -1;
            }else {
                pp[j][v] = pp[j - 1][pv];
            }
        }
    }

    rt = RangeTree(n);

    set< pii > Q;
    for(int u, v, iter = 0;iter < q;iter++) {
        scanf("%d %d", &u, &v);
        if(u > v) swap(u, v);
        int t;
        if(Q.count({u, v})) {
            t = -1;
            Q.erase({u, v});
        }else {
            t = +1;
            Q.insert({u, v});
        }
        query(u, v, t);
        printf("%d\n", rt.get((int)Q.size()));
    }

    return 0;
}