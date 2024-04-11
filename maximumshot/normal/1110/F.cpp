#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

struct RangeTree {
    int n; // [1, n]
    vector< ll > pu, mn;

    RangeTree() = default;

    void inc(int v, ll x) {
        pu[v] += x;
        mn[v] += x;
    }

    void push(int v) {
        inc(v << 1, pu[v]);
        inc(v << 1 | 1, pu[v]);
        pu[v] = 0;
    }

    void merge(int v) {
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
    }

    void build(int v, int tl, int tr, ll *ar) {
        if (tl == tr) {
            mn[v] = ar[tl];
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            build(v << 1, tl, tm, ar);
            build(v << 1 | 1, tm + 1, tr, ar);
            merge(v);
        }
    }

    RangeTree(ll *ar, int n) {
        this->n = n;
        pu.resize(4 * n);
        mn.resize(4 * n);
        build(1, 1, n, ar);
    }

    void update(int v, int tl, int tr, int l, int r, ll x) {
        if (l <= tl && tr <= r) {
            inc(v, x);
        } else {
           int tm = (tl + tr) >> 1;
           push(v);
           if (l <= tm) {
               update(v << 1, tl, tm, l, r, x);
           }
           if (r > tm) {
               update(v << 1 | 1, tm + 1, tr, l, r, x);
           }
           merge(v);
        }
    }

    void update(int l, int r, ll x) {
        if (l > r) {
            return;
        }
        update(1, 1, n, l, r, x);
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return mn[v];
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            ll res = inf64;
            if (l <= tm) {
                res = min(res, query(v << 1, tl, tm, l, r));
            }
            if (r > tm) {
                res = min(res, query(v << 1 | 1, tm + 1, tr, l, r));
            }
            merge(v);
            return res;
        }
    }

    ll getMin(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

const int N = 5e5 + 5;

int n, q;
int p[N], w[N];

struct Query {
    int v, l, r, id;
};

vector< Query > qs[N];
ll res[N];
int euler[N], cur = 1;
pii seg[N];
vector< pii > g[N];
vector< int > leafs;
ll S[N];

void dfs(int v) {
    if(v > 1) {
        S[v] = S[p[v]] + w[v];
    } else {
        S[v] = 0;
    }
    if(g[v].empty()) {
        seg[v] = {cur, cur};
        leafs.push_back(v);
    } else {
        seg[v] = {inf, -inf};
    }
    euler[v] = cur++;
    for(pii ed : g[v]) {
        int to = ed.first;
        dfs(to);
        seg[v].first = min(seg[v].first, seg[to].first);
        seg[v].second = max(seg[v].second, seg[to].second);
    }
}

RangeTree rt;

void go(int v) {
    for (Query qi : qs[v]) {
        res[qi.id] = rt.getMin(qi.l, qi.r);
    }
    for (pii ed : g[v]) {
        int to = ed.first;
        int we = ed.second;
        int lx = seg[to].first;
        int rx = seg[to].second;
        rt.update(lx, rx, -we);
        rt.update(1, lx - 1, +we);
        rt.update(rx + 1, n, +we);
        go(to);
        rt.update(lx, rx, +we);
        rt.update(1, lx - 1, -we);
        rt.update(rx + 1, n, -we);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &p[i], &w[i]);
        g[p[i]].push_back({i, w[i]});
    }

    for (int v = 1; v <= n; v++) {
        sort(g[v].begin(), g[v].end());
    }

    for (int it = 0; it < q; it++) {
        Query qi;
        scanf("%d %d %d", &qi.v, &qi.l, &qi.r);
        qi.id = it;
        qs[qi.v].push_back(qi);
    }

    dfs(1);

    for (int v = 1; v <= n; v++) {
        if(!g[v].empty()) {
            S[v] = inf64;
        }
    }

    rt = RangeTree(S, n);

    go(1);

    for (int i = 0; i < q; i++) {
        printf("%lld\n", res[i]);
    }

    return 0;
}