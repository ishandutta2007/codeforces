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

const int N = 5e5 + 5;

struct node_t {
    int l, r, minn, maxn, tag;
    ll sum;
} p[N << 2];

char c[N];
int n; ll ans;

void update(int u) {
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void add_tag(int u, int x) {
    p[u].minn = p[u].maxn = p[u].tag = x;
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
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void add(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        if (p[u].minn >= x) return;
        if (p[u].maxn <= x) {
            add_tag(u, x);
            return;
        }
        pushdown(u);
        add(u << 1, l, r, x);
        add(u << 1 | 1, l, r, x);
        update(u);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) add(u << 1, l, r, x);
    if (mid + 1 <= r) add(u << 1 | 1, l, r, x);
    update(u);
}

int main() {
    read(n); scanf("%s", c + 1);
    build(1, 1, n);
    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;
        if (c[l] == '0') {
            ans += p[1].sum;
            continue;
        }
        while (r < n && c[r + 1] == '1') ++r;
        for (int i = 1; i <= r - l + 1; i++) {
            ans += 1ll * i * (r - l + 1 - i + 1);
            if (l != 1) add(1, 1, l - 1, i); ans += p[1].sum;
        }
        for (int i = 1; i <= r - l + 1; i++) add(1, l + i - 1, l + i - 1, r - l + 1 - i + 1);
    }
    print(ans, '\n');
    return 0;
}