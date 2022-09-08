#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 1e6 + 5, MAXN = 1e6;

struct node_t { int l, r, tag, val, minn; } p[N << 2];

void update(int u) {
    p[u].val = 0;
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
    if (p[u].minn == p[u << 1].minn) p[u].val += p[u << 1].val;
    if (p[u].minn == p[u << 1 | 1].minn) p[u].val += p[u << 1 | 1].val;
}

void add_tag(int u, int x) {
    p[u].tag += x;
    p[u].minn += x;
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
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}

void add(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) add(u << 1, l, r, x);
    if (mid + 1 <= r) add(u << 1 | 1, l, r, x);
    update(u);
}

void change(int u, int x, int y) {
    if (p[u].l == p[u].r) {
        p[u].val = y;
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) change(u << 1, x, y);
    else change(u << 1 | 1, x, y);
    update(u);
}

void add(int l, int r, int x) {
    if (l > r) swap(l, r);
    l = max(l + 1, 1);
    r = min(r, MAXN);
    if (l <= r) add(1, l, r, x);
}

int a[N];
int n, q;

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    a[0] = MAXN + 1; a[n + 1] = -1;
    build(1, 1, MAXN);
    for (int i = 0; i <= n; i++) add(a[i], a[i + 1], 1);
    for (int i = 1; i <= n; i++) change(1, a[i], 1);
    for (int i = 1; i <= q; i++) {
        int pos, x;
        read(pos); read(x);
        add(a[pos - 1], a[pos], -1);
        add(a[pos], a[pos + 1], -1);
        change(1, a[pos], 0);
        a[pos] = x;
        add(a[pos - 1], a[pos], 1);
        add(a[pos], a[pos + 1], 1);
        change(1, a[pos], 1);
        print(p[1].val, '\n');
    }
    return 0;
}