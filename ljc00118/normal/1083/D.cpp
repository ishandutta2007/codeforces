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

const int md = 1e9 + 7;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 1e5 + 5;

ll s(int n) { return 1ll * n * (n + 1) / 2; }
ll s(int l, int r) { return s(r) - s(l - 1); }

// (L - l) * (r - R)
struct node_t {
    int l, r;
    int tagl, tagr;
    ll suml, sumr, sumlr, sumLr;
} p[N << 2];

map <int, int> las;
int a[N], l[N], r[N];
int n, ans;

void update(int u) {
    p[u].suml = p[u << 1].suml + p[u << 1 | 1].suml;
    p[u].sumr = p[u << 1].sumr + p[u << 1 | 1].sumr;
    p[u].sumlr = p[u << 1].sumlr + p[u << 1 | 1].sumlr;
    p[u].sumLr = p[u << 1].sumLr + p[u << 1 | 1].sumLr;
}

void add_tagl(int u, int x) {
    p[u].tagl = x;
    p[u].suml = 1ll * x * (p[u].r - p[u].l + 1);
    p[u].sumlr = 1ll * x * p[u].sumr;
}

void add_tagr(int u, int x) {
    p[u].tagr = x;
    p[u].sumr = 1ll * x * (p[u].r - p[u].l + 1);
    p[u].sumlr = 1ll * x * p[u].suml;
    p[u].sumLr = 1ll * x * s(p[u].l, p[u].r);
}

void pushdown(int u) {
    if (p[u].tagl) {
        add_tagl(u << 1, p[u].tagl);
        add_tagl(u << 1 | 1, p[u].tagl);
        p[u].tagl = 0;
    }
    if (p[u].tagr) {
        add_tagr(u << 1, p[u].tagr);
        add_tagr(u << 1 | 1, p[u].tagr);
        p[u].tagr = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        p[u].suml = ::l[l];
        p[u].sumr = ::r[l];
        p[u].sumlr = 1ll * p[u].suml * p[u].sumr;
        p[u].sumLr = 1ll * l * p[u].sumr;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    update(u);
}

int queryl(int u, int x) {
    if (p[u].l == p[u].r) return p[u].suml;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) return queryl(u << 1, x);
    return queryl(u << 1 | 1, x);
}

int queryr(int u, int x) {
    if (p[u].l == p[u].r) return p[u].sumr;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) return queryr(u << 1, x);
    return queryr(u << 1 | 1, x);
}

void changel(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        add_tagl(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) changel(u << 1, l, r, x);
    if (mid + 1 <= r) changel(u << 1 | 1, l, r, x);
    update(u);
}

void changer(int u, int l, int r, int x) {
    if (l <= p[u].l && p[u].r <= r) {
        add_tagr(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) changer(u << 1, l, r, x);
    if (mid + 1 <= r) changer(u << 1 | 1, l, r, x);
    update(u);
}

ll query(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) {
        ll res = p[u].sumLr + p[u].suml * r;
        // fprintf(stderr, "p[u].sumLr = %lld, p[u].suml = %lld, p[u].sumr = %lld, p[u].sumlr = %lld\n", p[u].sumLr, p[u].suml, p[u].sumr, p[u].sumlr);
        res -= p[u].sumlr;
        res -= s(p[u].l, p[u].r) * r;
        // fprintf(stderr, "res = %lld\n", res);
        return res;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1; ll res = 0;
    if (mid >= l) res += query(u << 1, l, r);
    if (mid + 1 <= r) res += query(u << 1 | 1, l, r);
    return res;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        if (las.count(a[i])) l[i] = las[a[i]] + 1;
        else l[i] = 1;
        las[a[i]] = i;
    }
    las.clear();
    for (int i = n; i >= 1; i--) {
        if (las.count(a[i])) r[i] = las[a[i]] - 1;
        else r[i] = n;
        las[a[i]] = i;
    }
    build(1, 1, n);
    for (int i = 1, pos = i; i <= n; i++) {
        int l = 1, r = i - 1, res = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (queryl(1, mid) < ::l[i]) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        changel(1, res, i, ::l[i]);
        l = 1; r = i - 1; res = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (queryr(1, mid) > ::r[i]) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        changer(1, res, i, ::r[i]);
        pos = max(pos, ::l[i]);
        // fprintf(stderr, "i = %d, pos = %d\n", i, pos);
        ans = (ans + query(1, pos, i)) % md;
    }
    print(ans, '\n');
    return 0;
}