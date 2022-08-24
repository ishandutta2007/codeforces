#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int LOG = 20;
const int MAXN = 120000;
int sp[LOG][MAXN];
int b[MAXN];
int nr[MAXN];
int n; 
int k;
int gmn;

void buildsp() {
    for (int i = 0; i < n; ++i)
        sp[0][i] = b[i];
    for (int i = 1; i < LOG; ++i)
        for (int j = 0; j < n; ++j) {
            if (j + (1 << i) > n)
                continue;
            sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
        }
    for (int i = 1; i <= n; ++i) {
        int k = 0;
        while ((1 << (k + 1)) <= i)
            ++k;
        nr[i] = k;
    }
}

int get2(int l, int r) {
    int k = nr[r - l];
    if (l == r)
        return 1e9 + 100;
    return min(sp[k][l], sp[k][r - (1 << k)]);
}

int gget(int l, int r) {
    if (r - l >= n)
        return gmn;
    l %= n;
    r %= n;
    if (l < r)
        return get2(l, r);
    else
        return min(get2(l, n), get2(0, r));
}

struct node {
    node *l, *r;
    int x, d;
    node(int L, int R) {
        l = r = 0;
        d = 0;
        x = gget(L, R);
    }
};

int get(node *v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l)
        return 1e9 + 100;
    if (!v) {
        l = max(l, tl);
        r = min(r, tr);
        return gget(l, r);
    }
    if (l <= tl && tr <= r)
        return v->x;
    if (v->d)
        return v->d;
    int m = (tl + tr) >> 1;
    return min(get(v->l, tl, m, l, r), get(v->r, m, tr, l, r));
}

void push(node *v, int tl, int tr) {
    int m = (tl + tr) >> 1;
    if (!v->l)
        v->l = new node(tl, m);
    if (!v->r)
        v->r = new node(m, tr);
    if (!v->d)
        return;
    v->l->x = v->l->d = v->d;
    v->r->x = v->r->d = v->d;
    v->d = 0;
}

void st(node *v, int tl, int tr, int l, int r, int x) {
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        v->d = x;
        v->x = x;
        return;
    }
    push(v, tl, tr);
    int m = (tl + tr) >> 1;
    st(v->l, tl, m, l, r, x);
    st(v->r, m, tr, l, r, x);
    v->x = min(v->l->x, v->r->x);
}

int main() {
    scanf("%d%d", &n, &k);
    gmn = 1e9 + 100;
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        gmn = min(gmn, b[i]);
    }
    buildsp();
    node *root = new node(0, n * k);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        --l;
        if (t == 1) {
            int x;
            scanf("%d", &x);
            st(root, 0, n * k, l, r, x);
        }
        else {
            printf("%d\n", get(root, 0, n * k, l, r));
        }
    }
    return 0;
}