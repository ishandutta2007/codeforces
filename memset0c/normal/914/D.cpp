// =================================
//   author: memset0
//   date: 2018.12.05 20:03:06
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}

template < class T >
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

#define gcd(a, b) std::__gcd(a, b)

const int N = 5e5 + 10;
int n, m, a[N];

struct node {
    int l, r, mid, gcd;
} p[N << 2];

void build(int u, int l, int r) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    if (l == r) { p[u].gcd = a[l]; return; }
    build(u << 1, l, p[u].mid);
    build(u << 1 | 1, p[u].mid + 1, r);
    p[u].gcd = gcd(p[u << 1].gcd, p[u << 1 | 1].gcd);
}

void modify(int u, int k, int w) {
    if (p[u].l == p[u].r) { p[u].gcd = w; return; }
    if (k <= p[u].mid) modify(u << 1, k, w);
    else modify(u << 1 | 1, k, w);
    p[u].gcd = gcd(p[u << 1].gcd, p[u << 1 | 1].gcd);
}   

int query(int u, int l, int r, int w) {
    // printf("query %d %d %d %d\n", u, l, r, w);
    if (p[u].l == p[u].r) return p[u].gcd % w != 0;
    if (p[u].l == l && p[u].r == r) {
        bool lc = p[u << 1].gcd % w;
        bool rc = p[u << 1 | 1].gcd % w;
        // printf(">> %d %d : %d %d\n", lc, rc, p[u << 1].gcd, p[u << 1 | 1].gcd);
        if (lc && rc) return 2;
        if (!lc && !rc) return 0;
        if (lc) return query(u << 1, l, p[u].mid, w);
        return query(u << 1 | 1, p[u].mid + 1, r, w);
    }
    if (r <= p[u].mid) return query(u << 1, l, r, w);
    if (l > p[u].mid) return query(u << 1 | 1, l, r, w);
    return query(u << 1, l, p[u].mid, w) +
        query(u << 1 | 1, p[u].mid + 1, r, w);
}

void main() {
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    build(1, 1, n);
    read(m);
    for (int i = 1, k, l, r, w, op; i <= m; i++) {
        read(op);
        if (op == 1) {
            read(l), read(r), read(w);
            bool ans = query(1, l, r, w) <= 1;
            puts(ans ? "YES" : "NO");
        } else {
            read(k), read(w);
            modify(1, k, w);
        }
    }
}

} signed main() { return ringo::main(), 0; }