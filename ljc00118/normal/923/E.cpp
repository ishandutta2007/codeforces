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
    vector <int> rev, roots, one(1, 1);

    vector <int> operator + (vector <int> a, vector <int> b) {
        int n = max((int)a.size(), (int)b.size()); a.resize(n); b.resize(n);
        for (int i = 0; i < n; i++) { a[i] = add(a[i], b[i]); } return a;
    }

    vector <int> operator - (vector <int> a, vector <int> b) {
        int n = max((int)a.size(), (int)b.size()); a.resize(n); b.resize(n);
        for (int i = 0; i < n; i++) { a[i] = sub(a[i], b[i]); } return a;
    }

    void getRevRoot(int base) {
        int n = 1 << base;
        rev.resize(n); roots.resize(n);
        for (int i = 1; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base - 1));
        for (int mid = 1; mid < n; mid <<= 1) {
            int wn = fpow(3, (md - 1) / (mid << 1));
            roots[mid] = 1;
            for (int i = 1; i < mid; i++) roots[mid + i] = mul(roots[mid + i - 1], wn);
        }
    }

    void ntt(vector <int> &a, int base) {
        int n = 1 << base;
        for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
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
        int base = 0, n = (int)a.size() + (int)b.size() - 1;
        while ((1 << base) < n) ++base;
        a.resize(1 << base); b.resize(1 << base);
        getRevRoot(base); ntt(a, base); ntt(b, base);
        for (int i = 0; i < (1 << base); i++) a[i] = mul(a[i], b[i]);
        reverse(a.begin() + 1, a.end()); ntt(a, base);
        a.resize(n); int inv = fpow(1 << base, md - 2);
        for (int i = 0; i < n; i++) { a[i] = mul(a[i], inv); } return a;
    }
}

using Poly::operator *;

const int N = 1e5 + 5;

vector <int> f, g, tmp;
int fac[N], inv[N];
int n; ll m;

int main() {
	read(n); read(m); f.resize(n + 1); tmp.resize(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
	inv[n] = fpow(fac[n], md - 2);
	for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	for (int i = 0; i <= n; i++) read(f[i]), tmp[i] = inv[i];
	for (int i = 0; i <= n; i++) f[i] = mul(f[i], fac[i]);
	reverse(f.begin(), f.end()); g = f * tmp; g.resize(n + 1); reverse(g.begin(), g.end());
	for (int i = 0; i <= n; i++) g[i] = mul(mul(g[i], inv[i]), fpow(fpow(i + 1, m % (md - 1)), md - 2));
	for (int i = 1; i <= n; i += 2) tmp[i] = md - tmp[i];
	for (int i = 0; i <= n; i++) g[i] = mul(g[i], fac[i]);
	reverse(g.begin(), g.end()); f = g * tmp; f.resize(n + 1); reverse(f.begin(), f.end());
	for (int i = 0; i <= n; i++) f[i] = mul(f[i], inv[i]), print(f[i], i == n ? '\n' : ' ');
    return 0;
}