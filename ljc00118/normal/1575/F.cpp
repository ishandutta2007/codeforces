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

int a[N], f[N], fac[N], inv[N], t[N], tt[N], pw[N];
int n, k, ans;

inline int C(int n, int m) {
    if (n < m || m < 0) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = fpow(fac[N - 1], md - 2);
    for (int i = N - 1; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    read(n); read(k);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], k - 1);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 0; i < n; i++) {
        int tem = fpow(n - i, md - 2);
        int c2 = mul(sub(0, mul(i, k - 1)), tem);
        int c1 = mul(sub(mul(n, k), add(i, mul(n - i, k - 1))), tem);
        int c0 = mul(sub(0, mul(k, i)), tem);
        f[i + 1] = add(c0, mul(c1, f[i]));
        if (i != 0) f[i + 1] = add(f[i + 1], mul(c2, f[i - 1]));
    }
    sort(a + 1, a + n + 1);
    int cnt = 0; t[0] = k;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while (r < n && a[r + 1] == a[l]) ++r;
        if (a[l] == -1) {
            cnt = r - l + 1;
            continue;
        }
        ++t[r - l + 1]; --t[0];
    }
    for (int i = 0; i <= n; i++) {
        if (t[i]) {
            for (int j = 0; j <= cnt; j++) {
                tt[i + j] = add(tt[i + j], mul(t[i], mul(C(cnt, j), pw[cnt - j])));
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        ans = add(ans, mul(tt[i], f[i]));
    }
    ans = mul(ans, fpow(fpow(k, cnt), md - 2));
    print(sub(ans, f[n]), '\n');
    return 0;
}