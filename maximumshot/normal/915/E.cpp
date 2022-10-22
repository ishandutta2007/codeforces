#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 1e6 + 5;

int n, q;
tuple< int, int, int > query[N];
int crd[N];
int sz;
int tree[4 * N];
int delt[4 * N];

inline void merge(int v) {
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
    delt[v] = -1;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v] = crd[tl + 1] - crd[tl];
        delt[v] = -1;
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        merge(v);
    }
}

inline void push(int v, int tl, int tm, int tr) {
    if(delt[v] == -1) return;
    delt[v << 1] = delt[v << 1 | 1] = delt[v];
    tree[v << 1] = delt[v] * (crd[tm + 1] - crd[tl]);
    tree[v << 1 | 1] = delt[v] * (crd[tr + 1] - crd[tm + 1]);
    delt[v] = -1;
}

void update(int v, int tl, int tr, int l, int r, int k) {
    if(l <= tl && tr <= r) {
        tree[v] = k * (crd[tr + 1] - crd[tl]);
        delt[v] = k;
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if(l <= tm) {
            update(v << 1, tl, tm, l, r, k);
        }
        if(r > tm) {
            update(v << 1 | 1, tm + 1, tr, l, r, k);
        }
        merge(v);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int k, l, r, i = 0;i < q;i++) {
        scanf("%d %d %d", &l, &r, &k);
        k = k == 1 ? 0 : 1;
        query[i] = make_tuple(l, r, k);
        crd[++sz] = l;
        crd[++sz] = r + 1;
    }

    crd[++sz] = 1;
    crd[++sz] = n + 1;

    sort(crd + 1, crd + sz + 1);
    sz = unique(crd + 1, crd + sz + 1) - (crd + 1);

    build(1, 1, sz - 1);

    for(int l, r, k, i = 0;i < q;i++) {
        tie(l, r, k) = query[i];

        l = lower_bound(crd + 1, crd + sz + 1, l) - (crd + 1) + 1;
        r = lower_bound(crd + 1, crd + sz + 1, r + 1) - (crd + 1);

        update(1, 1, sz - 1, l, r, k);

        printf("%d\n", tree[1]);
    }

    return 0;
}