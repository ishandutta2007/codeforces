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

const int N = 2e5 + 5;

struct node_t {
    int l, r, minn, maxn, tag;
    ll sum;
} p[N << 2];

int a[N];
int n, q;

void update(int u) {
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void add_tag(int u, int x) {
    p[u].tag = p[u].minn = p[u].maxn = x;
    p[u].sum = 1ll * (p[u].r - p[u].l + 1) * x;
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
        p[u].maxn = p[u].minn = p[u].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        if (p[u].minn >= x) return;
        if (x >= p[u].maxn) {
            add_tag(u, x);
            return;
        }
        pushdown(u);
        change(u << 1, l, r, x);
        change(u << 1 | 1, l, r, x);
        update(u);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) change(u << 1, l, r, x);
    if (mid + 1 <= r) change(u << 1 | 1, l, r, x);
    update(u);
}

ll query(int u, int l, int r) {
    if (l > r) return 0;
    if (l <= p[u].l && p[u].r <= r) return p[u].sum;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1; ll ans = 0;
    if (mid >= l) ans += query(u << 1, l, r);
    if (mid + 1 <= r) ans += query(u << 1 | 1, l, r);
    return ans;
}

int find1(int u, int l, int r, int x) {
    if (p[u].minn > x) return -1;
    if (l <= p[u].l && p[u].r <= r) {
        if (p[u].l == p[u].r) return p[u].l;
        pushdown(u);
        int ans = find1(u << 1, l, r, x);
        if (ans != -1) return ans;
        return find1(u << 1 | 1, l, r, x);
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) {
        int ans = find1(u << 1, l, r, x);
        if (ans != -1) return ans;
    }
    return find1(u << 1 | 1, l, r, x);
}

int find2(int u, ll x) {
    if (p[u].l == p[u].r) {
        if (p[u].sum <= x) return p[u].l;
        return p[u].l - 1;
    }
    pushdown(u);
    if (p[u << 1].sum <= x) return find2(u << 1 | 1, x - p[u << 1].sum);
    return find2(u << 1, x);
}

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    while (q--) {
        int opt, x, y;
        read(opt); read(x); read(y);
        if (opt == 1) change(1, 1, x, y);
        if (opt == 2) {
            int ans = 0;
            while (x <= n) {
                int pos = find1(1, x, n, y);
                if (pos == -1) break;
                int res = find2(1, y + query(1, 1, pos - 1));
                // fprintf(stderr, "pos = %d, res = %d, y = %d\n", pos, res, y);
                y -= query(1, pos, res); ans += (res - pos + 1); x = res + 2;
            }
            print(ans, '\n');
        }
    }
    return 0;
}