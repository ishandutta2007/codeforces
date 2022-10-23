#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 2e5 + 5;

struct node_t {
    int l, r;
    int minn, tag, mxl, mxr, maxn, sum;
} p[N << 2];

void update(int u) {
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    if (p[u << 1].minn == p[u << 1 | 1].minn) {
        p[u].mxl = p[u << 1].mxl;
        p[u].mxr = p[u << 1 | 1].mxr;
        p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum + max(p[u << 1].mxr, p[u << 1 | 1].mxl);
    } else if (p[u << 1].minn < p[u << 1 | 1].minn) {
        p[u].mxl = p[u << 1].mxl;
        p[u].mxr = max(p[u << 1].mxr, p[u << 1 | 1].maxn);
        p[u].sum = p[u << 1].sum;
    } else {
        p[u].mxr = p[u << 1 | 1].mxr;
        p[u].mxl = max(p[u << 1].maxn, p[u << 1 | 1].mxl);
        p[u].sum = p[u << 1 | 1].sum;
    }
}

void add_tag(int u, int x) {
    p[u].minn += x;
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
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

int w[N];
void modify(int u, int x) {
    if (p[u].l == p[u].r) {
        p[u].mxl = w[x]; p[u].mxr = w[x + 1];
        p[u].maxn = max(w[x], w[x + 1]);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) modify(u << 1, x);
    else modify(u << 1 | 1, x);
    update(u);
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

set <int> pos[N];
int a[N];
int n, q;

void del(int id) {
    if (!pos[id].size()) return;
    int l = *pos[id].begin(), r = *pos[id].rbegin();
    if (l != r) add(1, l, r - 1, -1);
    w[l] = 0;
    if (l - 1) modify(1, l - 1);
    if (l != n) modify(1, l);
}

void ins(int id) {
    if (!pos[id].size()) return;
    int l = *pos[id].begin(), r = *pos[id].rbegin();
    if (l != r) add(1, l, r - 1, 1);
    w[l] = pos[id].size();
    if (l - 1) modify(1, l - 1);
    if (l != n) modify(1, l);
}

void solve() {
    int ret;
    if (p[1].minn != 0) ret = p[1].maxn;
    else ret = p[1].sum + p[1].mxl + p[1].mxr;
    print(n - ret, '\n');
}

int main() {
    read(n); read(q);
    if (n == 1) {
        for (int i = 1; i <= q + 1; i++) print(0, '\n');
        return 0;
    }
    for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]].insert(i);
    build(1, 1, n - 1);
    for (int i = 1; i <= 200000; i++) ins(i);
    solve();
    for (int i = 1; i <= q; i++) {
        int x, y;
        read(x); read(y);
        if (a[x] != y) {
            del(a[x]); del(y); pos[a[x]].erase(x);
            swap(a[x], y);
            pos[a[x]].insert(x); ins(a[x]); ins(y);
        }
        solve();
    }
    return 0;
}