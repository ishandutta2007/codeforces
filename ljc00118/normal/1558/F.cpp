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

const int N = 2e5 + 5, INF = 1e9;

struct node_t { int l, r, minn, tag; } p[N << 2];

int a[N], pos[N], vis[N];
int T, n;

void update(int u) {
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
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
    p[u].l = l; p[u].r = r; p[u].tag = 0;
    if (l == r) {
        p[u].minn = INF + l;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
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

int query(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) return p[u].minn;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1, ans = INF;
    if (mid >= l) ans = min(ans, query(u << 1, l, r));
    if (mid + 1 <= r) ans = min(ans, query(u << 1 | 1, l, r));
    return ans;
}

int main() {
    read(T);
    while (T--) {
        read(n);
        memset(vis, 0, (n + 1) * 4);
        for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]] = i;
        build(1, 1, n);
        int r = n, ans = 0;
        for (int i = n; i >= 1; i--) {
            int p = pos[i];
            vis[p] = 1;
            while (vis[r]) --r;
            if (p != n) add(1, p + 1, n, -2);
            add(1, p, p, -INF);
            if (r == i - 1) continue;
            // fprintf(stderr, "n = %d, r = %d\n", n, r);
            int fir = query(1, 1, r);
            // fprintf(stderr, "fir = %d\n", fir);
            if (fir & 1) ans = max(ans, i - fir);
            else ans = max(ans, i - fir + 1);
            // fprintf(stderr, "ans = %d\n", ans);
        }
        print(ans, '\n');
    }
    return 0;
}