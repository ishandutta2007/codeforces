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

const int N = 3e5 + 5;

struct node_t { int l, r, val, tag; } p[N << 2];

int a[N], b[N], pos[N];
int n, ans;

void update(int u) { p[u].val = min(p[u << 1].val, p[u << 1 | 1].val); }

void add_tag(int u, int x) {
    p[u].val += x;
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
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
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

int query(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) return p[u].val;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1, ans = 233333;
    if (mid >= l) ans = min(ans, query(u << 1, l, r));
    if (mid + 1 <= r) ans = min(ans, query(u << 1 | 1, l, r));
    return ans;
}

int main() {
    read(n); ans = n;
    for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]] = i;
    for (int i = 1; i <= n; i++) read(b[i]);
    build(1, 1, n); change(1, pos[ans], n, 1);
    for (int i = 1; i <= n; i++) {
        // fprintf(stderr, ">>> %d %d %d\n", pos[ans], query(1, pos[ans] - 1, pos[ans] - 1), query(1, pos[ans], n));
        while (query(1, pos[ans], n) <= min(0, pos[ans] == 1 ? 0 : query(1, 1, pos[ans] - 1))) {
            --ans;
            change(1, pos[ans], n, 1);
        }
        print(ans, ' '); change(1, b[i], n, -1);
    }
    putchar('\n');
    return 0;
}