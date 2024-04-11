#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

const int N = 2e5 + 5;

class Tree {
private:
    int n; // [0 .. n]
    vec< ll > delt;
    vec< ll > mn;
public:
    Tree(): n(0) { }

    Tree(int _n) : n(_n) {
        delt.resize(4 * (n + 1));
        mn.resize(4 * (n + 1));
    }

    void update(int l, int r, ll val) {
        update(0, 0, n, l, r, val);
    }

    ll get_min(int l, int r) {
        return get_min(0, 0, n, l, r);
    }

private:

    void push(int v) {
        if(delt[v]) {
            delt[v * 2 + 1] += delt[v];
            delt[v * 2 + 2] += delt[v];
            mn[v * 2 + 1] += delt[v];
            mn[v * 2 + 2] += delt[v];
            delt[v] = 0;
        }
    }

    void merge(int v) {
        delt[v] = 0;
        mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    }

    void update(int v, int tl, int tr, int l, int r, ll val) {
        if(l <= tl && tr <= r) {
            delt[v] += val;
            mn[v] += val;
        }else {
            int tm = (tl + tr) / 2;
            push(v);
            if(l <= tm) {
                update(v * 2 + 1, tl, tm, l, r, val);
            }
            if(r > tm) {
                update(v * 2 + 2, tm + 1, tr, l, r, val);
            }
            merge(v);
        }
    }

    ll get_min(int v, int tl, int tr, int l, int r) {
        if(l <= tl && tr <= r) {
            return mn[v];
        }else {
            int tm = (tl + tr) / 2;
            push(v);
            ll res = inf64;
            if(l <= tm) {
                res = min(res, get_min(v * 2 + 1, tl, tm, l, r));
            }
            if(r > tm) {
                res = min(res, get_min(v * 2 + 2, tm + 1, tr, l, r));
            }
            merge(v);
            return res;
        }
    }
};

int n, m, Q;
int x[N];
int y[N];
vec< pii > g[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &Q);

    for(int i = 1;i < n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int u, v, w, i = 0;i < m;i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
    }

//    vec< ll > cut(n + 1);
    vec< ll > best(n + 1, inf64);

    Tree cut(n);

    for(int i = 0;i <= n;i++) {
        cut.update(i, i, y[i]);
    }

    for(int i = 1;i <= n;i++) {
        for(pii iter : g[i]) {
            int j, w;
            tie(j, w) = iter;
//            for(int q = 0;q < j;q++) {
//                cut[q] += w;
//            }
            if(j > 0) {
                cut.update(0, j - 1, w);
            }
        }
        int mn = n;
//        for(int j = i + 1;j <= n;j++) {
//            for(pii iter : g[j]) {
//                mn = min(mn, iter.first);
//            }
//        }
//        for(int j = 0;j < mn;j++) {
//            best[i] = min(best[i], cut[j] + y[j]);
//        }
        if(mn > 0) {
            best[i] = cut.get_min(0, mn - 1);
        }
    }

    Tree min_tree(n);

    for(int i = 1;i <= n;i++) {
        min_tree.update(i, i, x[i] + best[i]);
    }

    for(int v, w, iter = 0;iter <= Q;iter++) {
        if(iter > 0) {
            scanf("%d %d", &v, &w);
            min_tree.update(v, v, w - x[v]);
            x[v] = w;
        }
        ll res = inf64;
//        for(int i = 1;i <= n;i++) {
//            res = min(res, x[i] + best[i]);
//        }
        res = min_tree.get_min(1, n);
        cout << res << "\n";
    }

    return 0;
}