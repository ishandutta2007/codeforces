#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 300005;

struct Node {
    int len;
    ll lx, rx;
    int pref, suff;
    int left_mount;
    int right_mount;
    int res;
    ll delt;
} tree[4 * N];

Node merge(Node const & l, Node const & r) {
    Node ans;

    ans.delt = 0;
    ans.len = l.len + r.len;
    ans.lx = l.lx;
    ans.rx = r.rx;

    if(l.pref == l.len && l.rx > r.lx) {
        ans.pref = l.pref + r.pref;
    }else {
        ans.pref = l.pref;
    }

    if(r.suff == r.len && r.lx > l.rx) {
        ans.suff = r.suff + l.suff;
    }else {
        ans.suff = r.suff;
    }

    ans.left_mount = l.left_mount;
    if(l.left_mount == l.len && l.rx > r.lx) {
        ans.left_mount = max(
            ans.left_mount,
            l.left_mount + r.pref
        );
    }
    if(l.suff == l.len && l.rx < r.lx) {
        ans.left_mount = max(
            ans.left_mount,
            l.suff + r.left_mount
        );
    }

    ans.right_mount = r.right_mount;
    if(r.right_mount == r.len && r.lx > l.rx) {
        ans.right_mount = max(
            ans.right_mount,
            r.right_mount + l.suff
        );
    }
    if(r.pref == r.len && r.lx < l.rx) {
        ans.right_mount = max(
            ans.right_mount,
            r.pref + l.right_mount
        );
    }

    ans.res = max(l.res, r.res);
    if(r.lx > l.rx) ans.res = max(ans.res, r.left_mount + l.suff);
    if(l.rx > r.lx) ans.res = max(ans.res, l.right_mount + r.pref);

    return ans;
}

int n;
int a[N];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v].len = 1;
        tree[v].lx = a[tl];
        tree[v].rx = a[tl];
        tree[v].pref = 1;
        tree[v].suff = 1;
        tree[v].left_mount = 1;
        tree[v].right_mount = 1;
        tree[v].res = 1;
        tree[v].delt = 0;
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
}

void push(int v) {
    if(tree[v].delt) {
        tree[v << 1].lx += tree[v].delt;
        tree[v << 1].rx += tree[v].delt;
        tree[v << 1].delt += tree[v].delt;

        tree[v << 1 | 1].lx += tree[v].delt;
        tree[v << 1 | 1].rx += tree[v].delt;
        tree[v << 1 | 1].delt += tree[v].delt;

        tree[v].delt = 0;
    }
}

void inc(int v, int tl, int tr, int l, int r, int d) {
    if(l <= tl && tr <= r) {
        tree[v].lx += d;
        tree[v].rx += d;
        tree[v].delt += d;
    }else {
        int tm = (tl + tr) >> 1;
        push(v);
        if(l <= tm) inc(v << 1, tl, tm, l, r, d);
        if(r > tm) inc(v << 1 | 1, tm + 1, tr, l, r, d);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    build(1, 1, n);

    int m;

    scanf("%d", &m);

    for(int l, r, d, iter = 1;iter <= m;iter++) {
        scanf("%d %d %d", &l, &r, &d);
        inc(1, 1, n, l, r, d);
        printf("%d\n", tree[1].res);
    }

    return 0;
}