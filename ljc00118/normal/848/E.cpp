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

const int N = 50005, md = 998244353;

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
        if ((int)roots.size() == n) return;
        roots.resize(n); rev.resize(n);
        for (int i = 1; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base - 1));
        for (int mid = 1; mid < n; mid <<= 1) {
            int wn = fpow(3, (md - 1) / (mid << 1));
            roots[mid] = 1;
            for (int i = 1; i < mid; i++) roots[i + mid] = mul(roots[i + mid - 1], wn);
        }
    }

    void ntt(vector <int> &a, int base) {
        int n = 1 << base;
        for (int i = 1; i < n; i++) {
            if (i < rev[i]) {
                swap(a[i], a[rev[i]]);
            }
        }
        for (int mid = 1; mid < n; mid <<= 1) {
            for (int i = 0; i < n; i += (mid << 1)) {
                for (int j = 0; j < mid; j++) {
                    int x = a[i + j], y = mul(a[i + j + mid], roots[mid + j]);
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
        reverse(a.begin() + 1, a.end()); ntt(a, base); a.resize(n);
        int inv = fpow(1 << base, md - 2);
        for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
        return a;
    }
}

using Poly::operator *;

vector <int> f0, f1, f2, g0, g1, g2, tmp;
int F0[N], F1[N], F2[N], G0[N], G1[N], G2[N], g[N];
int n, ans;

void cdq(int l, int r) {
    if (l == r) {
        F0[l] = add(F0[l], G0[l]);
        F1[l] = add(F1[l], G1[l]);
        F2[l] = add(F2[l], G2[l]);
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid);
    f0.resize(mid - l + 1); f1.resize(mid - l + 1); f2.resize(mid - l + 1);
    for (int i = l; i <= mid; i++) {
        f0[i - l] = F0[i];
        f1[i - l] = F1[i];
        f2[i - l] = F2[i];
    }
    g0.resize(r - l + 1); g1.resize(r - l + 1); g2.resize(r - l + 1);
    for (int i = 0; i <= r - l; i++) {
        g0[i] = G0[i];
        g1[i] = G1[i];
        g2[i] = G2[i];
    }
    tmp = f0 * g0;
    for (int i = mid - l + 1; i <= r - l; i++) F0[i + l] = add(F0[i + l], tmp[i]);
    tmp = f1 * g0;
    for (int i = mid - l + 1; i <= r - l; i++) F1[i + l] = add(F1[i + l], tmp[i]);
    tmp = f1 * g1;
    for (int i = mid - l + 1; i <= r - l; i++) F0[i + l] = add(F0[i + l], tmp[i]);
    for (int i = mid - l + 1; i <= r - l; i++) F2[i + l] = add(F2[i + l], tmp[i]);
    tmp = f2 * g1;
    for (int i = mid - l + 1; i <= r - l; i++) F1[i + l] = add(F1[i + l], tmp[i]);
    tmp = f2 * g2;
    for (int i = mid - l + 1; i <= r - l; i++) F2[i + l] = add(F2[i + l], tmp[i]);
    cdq(mid + 1, r);
}

int main() {
    read(n);
    g[0] = 1;
    for (int i = 2; i <= n; i += 2) {
        g[i] = g[i - 2];
        if (i >= 4) g[i] = add(g[i], g[i - 4]);
    }
    for (int i = 1; i <= n; i++) G0[i] = mul(g[i - 1], mul(i - 1, i - 1));
    for (int i = 2; i <= n; i++) G1[i] = mul(g[i - 2], mul(i - 1, i - 1));
    for (int i = 3; i <= n; i++) G2[i] = mul(g[i - 3], mul(i - 1, i - 1));
    cdq(1, n);
    ans = mul(n, add(G0[n], G2[n]));
    for (int i = 0; i <= n; i++) {
        int res = 0;
        res = add(res, mul(F0[i], G0[n - i]));
        res = add(res, mul(2, mul(F1[i], G1[n - i])));
        res = add(res, mul(F2[i], G2[n - i]));
        ans = add(ans, mul(res, n - i));
    }
    print(ans, '\n');
    return 0;
}