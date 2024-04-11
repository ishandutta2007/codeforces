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

int md;

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

const int N = 405;

int f[N][N], fac[N], inv[N], tem[N];
int n;

inline int C(int n, int m) {
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    read(n); read(md);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    inv[n] = fpow(fac[n], md - 2);
    for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    tem[1] = 1; tem[2] = 1;
    for (int i = 3; i <= n; i++) {
        // tem[i] = mul(inv[i], 2 + (i - 2) * 2);
        for (int j = 1; j <= n; j++) addx(tem[i], C(i - 1, j - 1));
        tem[i] = mul(tem[i], inv[i]);
    }
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) f[i][i] = tem[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= n - i - 1; k++) {
                int coef = tem[k];
                addx(f[i + k + 1][j + k], mul(f[i][j], coef));
            }
            // fprintf(stderr, "f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) addx(ans, mul(f[n][i], fac[i]));
    print(ans, '\n');
    return 0;
}