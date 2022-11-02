#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1<<17;
const int MAXB = 20;

int n, m, ar[MAXN];
int tree[MAXB][2*MAXN], lazy[MAXB][2*MAXN];

void init(int c, int cur, int lt, int rt) {
    if (lt + 1 == rt)
        tree[c][cur] = bool(ar[lt] & 1<<c);
    else {
        int mid = (lt + rt) / 2;
        init(c, 2*cur, lt, mid);
        init(c, 2*cur+1, mid, rt);
        tree[c][cur] = tree[c][2*cur] + tree[c][2*cur+1];
    }
}

void down(int c, int cur, int lt, int rt) {
    if (lazy[c][cur]) {
        tree[c][cur] = rt - lt - tree[c][cur];
        if (lt + 1 != rt)
            lazy[c][2*cur] ^= 1, lazy[c][2*cur+1] ^= 1;
        lazy[c][cur] = 0;
    }
}

int query(int c, int cur, int lt, int rt, int ql, int qr) {
    down(c, cur, lt, rt);
    if (rt <= ql || lt >= qr) return 0;
    if (lt >= ql && rt <= qr) return tree[c][cur];
    else {
        int mid = (lt + rt) / 2;
        return query(c, 2*cur, lt, mid, ql, qr)+query(c, 2*cur+1, mid, rt, ql, qr);
    }
}

void update(int c, int cur, int lt, int rt, int ql, int qr) {
    down(c, cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[c][cur] = 1;
        down(c, cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(c, 2*cur, lt, mid, ql, qr);
        update(c, 2*cur+1, mid, rt, ql, qr);
        tree[c][cur] = tree[c][2*cur] + tree[c][2*cur+1];
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &ar[i]);
    for (int i=0; i<MAXB; i++)
        init(i, 1, 0, n);
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            ll ans = 0;
            for (int j=0; j<MAXB; j++)
                ans += ll(1<<j)*query(j, 1, 0, n, l, r);
            printf("%I64d\n", ans);
        } else {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            l--;
            for (int j=0; j<MAXB; j++)
                if (x&1<<j)
                    update(j, 1, 0, n, l, r);
        }
    }
    return 0;
}