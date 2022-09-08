#include <bits/stdc++.h>
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int inv100 = fpow(100, md - 2);

struct ele { int a, b; };
struct node_t { int l, r; ele val; } p[N << 2];

ele operator + (const ele a, const ele b) {
    ele ans;
    ans.a = mul(a.a, b.a);
    ans.b = add(mul(a.b, b.a), b.b);
    return ans;
}

set <int> wxw;
set <int> :: iterator it;
int a[N], zt[N], P[105], inv[105];
int n, q, ans;

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].val.a = add(1, mul(sub(1, P[a[l]]), inv[a[l]]));
        p[u].val.b = inv[a[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    p[u].val = p[u << 1].val + p[u << 1 | 1].val;
}

ele query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) return p[u].val;
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l && mid + 1 <= r) return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    if(mid >= l) return query(u << 1, l, r);
    return query(u << 1 | 1, l, r);
}

inline int calc(int l, int r) {
    if(l == r) return inv[a[l]];
    ele tmp = query(1, l + 1, r);
    return add(mul(inv[a[l]], tmp.a), tmp.b);
}

int main() {
    read(n); read(q); zt[1] = 1; wxw.insert(1); wxw.insert(n + 1);
    for(register int i = 1; i <= 100; i++) P[i] = mul(i, inv100), inv[i] = fpow(P[i], md - 2);
    for(register int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    ans = calc(1, n);
    for(register int i = 1; i <= q; i++) {
        int x; read(x);
        if(zt[x] == 1) {
            int l = 0, r = 0;
            wxw.erase(x);
            it = wxw.lower_bound(x);
            r = *it; l = *(--it);
            ans = sub(ans, calc(l, x - 1));
            ans = sub(ans, calc(x, r - 1));
            ans = add(ans, calc(l, r - 1));
            zt[x] = 0;
        } else {
            int l = 0, r = 0;
            it = wxw.lower_bound(x);
            r = *it; l = *(--it);
            ans = add(ans, calc(l, x - 1));
            ans = add(ans, calc(x, r - 1));
            ans = sub(ans, calc(l, r - 1));
            wxw.insert(x);
            zt[x] = 1;
        }
        print(ans, '\n');
    }
    return 0;
}