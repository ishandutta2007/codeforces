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

const int md = 998244353;

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

int f[20][20][20][20][2][2], g[20][20][20][20][2][2], sx[32][2], sy[32][2];
int x[5], y[5];
int n, m;

int main() {
    read(n); read(m);
    for (int i = 0; i < n; i++) read(x[i]), read(y[i]);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            sx[i][x[j] > 0] += abs(x[j]);
            sy[i][y[j] > 0] += abs(y[j]);
        }
    }
    f[0][0][0][0][0][0] = 1;
    for (int i = 0; i <= 29; i++) {
        memset(g, 0, sizeof(g));
        rep(i0, 0, n * 4 - 1) rep(i1, 0, n * 4 - 1) rep(i2, 0, n * 4 - 1) rep(i3, 0, n * 4 - 1) rep(i4, 0, 1) rep(i5, 0, 1) {
            if (!f[i0][i1][i2][i3][i4][i5]) continue;
            for (int j = 0; j < (1 << n); j++) {
                if ((i0 + i1 + sx[j][0] + sx[j][1]) & 1) continue;
                if ((i2 + i3 + sy[j][0] + sy[j][1]) & 1) continue;
                int j0 = (i0 + sx[j][0]) >> 1, j1 = (i1 + sx[j][1]) >> 1, j2 = (i2 + sy[j][0]) >> 1, j3 = (i3 + sy[j][1]) >> 1;
                int j4 = ((i0 + sx[j][0]) & 1) == ((m >> i) & 1) ? i4 : ((i0 + sx[j][0]) & 1) > ((m >> i) & 1);
                int j5 = ((i2 + sy[j][0]) & 1) == ((m >> i) & 1) ? i5 : ((i2 + sy[j][0]) & 1) > ((m >> i) & 1);
                addx(g[j0][j1][j2][j3][j4][j5], f[i0][i1][i2][i3][i4][i5]);
            }
        }
        memcpy(f, g, sizeof(f));
    }
    print(sub(f[0][0][0][0][0][0], 1), '\n');
    return 0;
}