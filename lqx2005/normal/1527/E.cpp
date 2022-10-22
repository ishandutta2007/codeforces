#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))
using namespace std;
const int N = 35000 + 10, oo = 0x3f3f3f3f;
int n, k, a[N], pre[N], edp[N];
int f[N], g[N];
int mx[N << 1], tag[N << 1];

void upd(int p, int l, int r) {mx[p] = min(mx[lc], mx[rc]); }

void pushd(int p, int l, int r) {
    tag[lc] += tag[p], tag[rc] += tag[p], mx[lc] += tag[p], mx[rc] += tag[p];
    tag[p] = 0;
}

void build(int p, int l, int r) {
    tag[p] = 0;
    if(l == r) return mx[p] = f[l], void();
    build(lc, l, mid), build(rc, mid + 1, r);
    upd(p, l, r);
    return;
}

void modify(int p, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        mx[p] += v, tag[p] += v;
        return;
    }
    pushd(p, l, r);
    if(L <= mid) modify(lc, l, mid, L, R, v);
    if(R > mid) modify(rc, mid + 1, r, L, R, v);
    return upd(p, l, r);
}

int query(int p, int l, int r, int L, int R) {
    if(L <= l && r <= R) return mx[p];
    pushd(p, l, r);
    int res = oo;
    if(L <= mid) res = min(res, query(lc, l, mid, L, R));
    if(R > mid) res = min(res, query(rc, mid + 1, r, L, R));
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pre[i] = edp[a[i]], edp[a[i]] = i;
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for(int i = 1; i <= k; i++) {
        build(1, 0, n);
        g[0] = oo;
        for(int j = 1; j <= n; j++) {
            if(pre[j]) modify(1, 0, n, 0, pre[j] - 1, j - pre[j]);
            g[j] = query(1, 0, n, 0, j - 1);
        }
        memcpy(f, g, sizeof(g));
    }
    printf("%d\n", f[n]);
    return 0;
}