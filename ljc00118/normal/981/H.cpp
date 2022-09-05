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

const int md = 998244353;

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

namespace Poly {
    vector <int> roots, rev;

    void getRevRoot(int base) {
        int n = 1 << base;
        rev.resize(n); roots.resize(n);
        for (int i = 1; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base - 1));
        for (int mid = 1; mid < n; mid <<= 1) {
            int wn = fpow(3, (md - 1) / (mid << 1));
            roots[mid] = 1;
            for (int i = 1; i < mid; i++) {
                roots[i + mid] = mul(roots[i + mid - 1], wn);
            }
        }
    }

    void ntt(vector <int> &a, int base) {
        int n = 1 << base;
        for (int i = 0; i < n; i++) {
            if (i < rev[i]) {
                swap(a[i], a[rev[i]]);
            }
        }
        for (int mid = 1; mid < n; mid <<= 1) {
            for (int i = 0; i < n; i += (mid << 1)) {
                for (int j = 0; j < mid; j++) {
                    int x = a[i + j], y = mul(a[i + j + mid], roots[j + mid]);
                    a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
                }
            }
        }
    }

    vector <int> operator * (vector <int> a, vector <int> b) {
        int n = (int)a.size() + (int)b.size() - 1, base = 0;
        while ((1 << base) < n) ++base;
        a.resize(1 << base); b.resize(1 << base);
        getRevRoot(base); ntt(a, base); ntt(b, base);
        for (int i = 0; i < (1 << base); i++) a[i] = mul(a[i], b[i]);
        reverse(a.begin() + 1, a.end()); ntt(a, base);
        int inv = fpow(1 << base, md - 2);
        a.resize(n);
        for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
        return a;
    }
}

using Poly::operator *;

const int N = 1e5 + 5;

vector <int> adj[N], poly[N], res[30], tmp[30], res2, tmp2;
int cnt[N], fac[N], inv[N], siz[N], sumc[N], ss[N];
int n, k, sum, ans;

inline int A(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return mul(fac[n], inv[n - m]);
}

void solve(int dep, int l, int r) {
    if (l == r) {
        tmp[dep] = poly[l];
        return;
    }
    int mid = (l + r) >> 1;
    solve(dep + 1, l, mid);
    tmp[dep] = tmp[dep + 1];
    solve(dep + 1, mid + 1, r);
    tmp[dep] = tmp[dep] * tmp[dep + 1];
}

void dfs1(int u, int fa) {
    siz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dfs1(v, u); siz[u] += siz[v];
    }
    int len = 0;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        ++len;
        poly[len].resize(2);
        poly[len][0] = 1;
        poly[len][1] = siz[v];
    }
    if (!len) {
        cnt[u] = 1;
        return;
    }
    solve(0, 1, len);
    // if (u == 1) {
    //     fprintf(stderr, "%d %d %d %d\n", tmp[0][0], tmp[0][1], tmp[0][2], tmp[0][3]);
    // }
    for (int i = 0; i <= len; i++) cnt[u] = add(cnt[u], mul(tmp[0][i], A(k, i)));
}

vector <int> add(vector <int> a, vector <int> b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < (int)b.size(); i++) a[i] = add(a[i], b[i]);
    return a;
}

void solve2(int dep, int l, int r) {
    if (l == r) {
        tmp[dep] = poly[l];
        res[dep].resize(1);
        res[dep][0] = ss[l];
        return;
    }
    int mid = (l + r) >> 1;
    solve2(dep + 1, l, mid);
    tmp[dep] = tmp[dep + 1];
    res[dep] = res[dep + 1];
    solve2(dep + 1, mid + 1, r);
    res[dep] = add(res[dep] * tmp[dep + 1], tmp[dep] * res[dep + 1]);
    tmp[dep] = tmp[dep] * tmp[dep + 1];
    // fprintf(stderr, "tmp[%d].size() = %d, res[%d].size() = %d, len = %d\n", dep, (int)tmp[dep].size(), (int)res[dep].size(), r - l + 1);
}

void dfs2(int u, int fa) {
    sumc[u] = cnt[u];
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dfs2(v, u);
        sumc[u] = add(sumc[u], sumc[v]);
    }
    int len = 0;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        ans = sub(ans, mul(cnt[u], sumc[v]));
        ++len;
        poly[len].resize(2);
        poly[len][0] = 1;
        poly[len][1] = siz[v];
        ss[len] = sumc[v];
    }
    if (!len) return;
    solve2(0, 1, len);
    // fprintf(stderr, "res[0].size() = %d, len = %d\n", (int)res[0].size(), len);
    res[0].resize(len + 1);
    for (int i = len; i >= 1; i--) res[0][i] = add(res[0][i], mul(res[0][i - 1], n - siz[u]));
    for (int i = 0; i <= len; i++) ans = add(ans, mul(res[0][i], A(k, i)));
}

int main() {
    read(n); read(k);
    if (k == 1) {
        print(1ll * n * (n - 1) / 2 % md, '\n');
        return 0;
    }
    fac[0] = 1;
    for (int i = 1; i <= k; i++) fac[i] = mul(fac[i - 1], i);
    inv[k] = fpow(fac[k], md - 2);
    for (int i = k; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) sum = add(sum, cnt[i]);
    ans = mul(sum, sum);
    for (int i = 1; i <= n; i++) ans = sub(ans, mul(cnt[i], cnt[i]));
    ans = mul(ans, (md + 1) >> 1);
    dfs2(1, 0);
    print(ans, '\n');
    return 0;
}