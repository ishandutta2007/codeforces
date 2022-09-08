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

const int N = 1e5 + 5, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

struct event_t {
    int pos, v, dis, _a, _b;
    event_t (int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) : pos(a), v(b), dis(c), _a(d), _b(e) {}
} e[N << 1];

bool operator < (const event_t a, const event_t b) {
    // a.dis / a.v < a.dis / b.v
    return 1ll * a.dis * b.v < 1ll * b.dis * a.v;
}

struct mat { int a[2][2]; } p[N << 2];

mat operator * (const mat a, const mat b) {
    mat ans; memset(ans.a, 0, sizeof(ans.a));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ans.a[i][j] = add(ans.a[i][j], mul(a.a[i][k], b.a[k][j]));
                // if (mul(a.a[i][k], b.a[k][j])) {
                //     fprintf(stderr, "debug : %d %d %d %d %d %d\n", i, j, k, a.a[i][k], b.a[k][j], ans.a[i][j]);
                // }
            }
        }
    }
    return ans;
}

int a[N], v[N], P[N];
int n, tot, inv, lasv = 0, ans;

void update(int u) { p[u] = p[u << 1] * p[u << 1 | 1]; }

void build(int u, int l, int r) {
    if (l == r) {
        p[u].a[0][1] = p[u].a[1][1] = P[l];
        p[u].a[0][0] = p[u].a[1][0] = sub(1, P[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int L, int R, int x, int a, int b) {
    if (L == R) {
        p[u].a[a][b] = 0;
        return;
    }
    int mid = (L + R) >> 1;
    if (mid >= x) change(u << 1, L, mid, x, a, b);
    else change(u << 1 | 1, mid + 1, R, x, a, b);
    update(u);
}

int main() {
    read(n); inv = fpow(100, md - 2);
    for (int i = 1; i <= n; i++) read(a[i]), read(v[i]), read(P[i]), P[i] = mul(P[i], inv);
    for (int i = 2; i <= n; i++) {
        e[++tot] = event_t(i, v[i - 1] + v[i], a[i] - a[i - 1], 1, 0);
        if (v[i - 1] < v[i]) e[++tot] = event_t(i, v[i] - v[i - 1], a[i] - a[i - 1], 0, 0);
        if (v[i - 1] > v[i]) e[++tot] = event_t(i, v[i - 1] - v[i], a[i] - a[i - 1], 1, 1);
    }
    sort(e + 1, e + tot + 1);
    build(1, 1, n);
    for (int i = 1; i <= tot; i++) {
        int nowv = mul(e[i].dis, fpow(e[i].v, md - 2));
        ans = add(ans, mul(add(p[1].a[0][0], p[1].a[0][1]), sub(nowv, lasv)));
        lasv = nowv;
        change(1, 1, n, e[i].pos, e[i]._a, e[i]._b);
    }
    ans = sub(ans, mul(add(p[1].a[0][0], p[1].a[0][1]), lasv));
    print(ans, '\n');
    return 0;
}