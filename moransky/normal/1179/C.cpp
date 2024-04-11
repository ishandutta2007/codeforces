#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

#define ls (p << 1)
#define rs (p << 1 | 1)

const int N = 1e6 + 5;

int n, m, q, a[N], b[N], L = 1e6;

int mx[N << 2], add[N << 2];

void inline Add(int p, int k) {
    add[p] += k, mx[p] += k;
}

void inline pushup(int p) {
    mx[p] = max(mx[ls], mx[rs]);
}

void inline pushdown(int p) {
    if (add[p]) {
        Add(ls, add[p]);
        Add(rs, add[p]);
        add[p] = 0;
    }
}

void change(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) {
        Add(p, c);
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (x <= mid) change(ls, l, mid, x, y, c);
    if (mid < y) change(rs, mid + 1, r, x, y, c);
    pushup(p);
}

int inline query(int p, int l, int r) {
    if (mx[p] <= 0) return -1;
    if (l == r) return r;
    pushdown(p);
    int mid = (l + r) >> 1;
    if (mx[rs] > 0) return query(rs, mid + 1, r);
    else return query(ls, l, mid);
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        change(1, 1, L, 1, a[i], 1);
    }
    for (int i = 1; i <= m; i++) {
        read(b[i]);
        change(1, 1, L, 1, b[i], -1);
    }
    read(q);
    while (q--) {
        int op, i, x; read(op), read(i), read(x);
        if (op == 1) {
            change(1, 1, L, 1, a[i], -1);
            a[i] = x;
            change(1, 1, L, 1, a[i], 1);
        } else {
            change(1, 1, L, 1, b[i], 1);
            b[i] = x;
            change(1, 1, L, 1, b[i], -1);
        }
        printf("%d\n", query(1, 1, L));
    }
}