#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5, M = 1e6 + 1;

struct node_t { int l, r, tag, mx; } p[(M + 5) << 2];

struct ele {
    int a, b, c;
    ele (int x = 0, int y = 0, int z = 0) : a(x), b(y), c(z) {}
} a[N], b[N], c[N];

int n, m, k, bl, cl, ans = -2e9;

void update(int u) { p[u].mx = max(p[u << 1].mx, p[u << 1 | 1].mx); }

void add_tag(int u, int x) {
    p[u].mx += x;
    p[u].tag += x;
}

void pushdown(int u) {
    if (p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        p[u].mx = -2e9;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void setit(int u, int x, int y) {
    if (p[u].l == p[u].r) {
        p[u].mx = max(p[u].mx, y);
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) setit(u << 1, x, y);
    else setit(u << 1 | 1, x, y);
    update(u);
}

void change(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) change(u << 1, l, r, x);
    if (mid + 1 <= r) change(u << 1 | 1, l, r, x);
    update(u);
}

bool cmpa(ele a, ele b) { return a.a < b.a; }
bool cmpb(ele a, ele b) { return a.b < b.b; }

int main() {
    read(n); read(m); read(k);
    build(1, 1, M);
    for (int i = 1; i <= n; i++) read(a[i].a), read(a[i].b), setit(1, a[i].a, -a[i].b);
    for (int i = 1; i <= m; i++) read(b[i].a), read(b[i].b);
    for (int i = 1; i <= k; i++) read(c[i].a), read(c[i].b), read(c[i].c), ++c[i].a, ++c[i].b;
    sort(b + 1, b + m + 1, cmpa); sort(c + 1, c + k + 1, cmpb); bl = cl = 1;
    while (bl <= m) {
        if (cl <= k && c[cl].b <= b[bl].a) {
            change(1, c[cl].a, M, c[cl].c);
            ++cl;
        } else {
            ans = max(ans, p[1].mx - b[bl].b);
            ++bl;
        }
    }
    print(ans, '\n');
    return 0;
}