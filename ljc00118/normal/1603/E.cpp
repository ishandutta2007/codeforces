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

const int N = 205;

int f[N][N][N], fac[N], inv[N];
int n, ans;

bool check(int fir) {
    int sum = fir, now = fir;
    for (int i = 2; i <= n && now <= n + 1; i++) {
        while (fir * now < sum + now && now <= n + 1) ++now;
        sum += now;
    }
    return now <= n + 1;
}

int main() {
    read(n); read(md);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    inv[n] = fpow(fac[n], md - 2);
    for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for (int mn = 1; mn <= n + 1; mn++) {
        if (!check(mn)) continue;
        memset(f[mn - 1], 0, sizeof(f[mn - 1]));
        f[mn - 1][0][0] = 1;
        for (int i = mn; i <= n + 1; i++) {
            memset(f[i], 0, sizeof(f[i]));
            for (int j = 0; j <= i - 1; j++) {
                for (int k = 0; k <= n - (i - mn) * (n - j); k++) {
                    if (!f[i - 1][j][k]) continue;
                    int low = (i == mn || i == n + 1);
                    for (int t = low; t <= (i == mn ? i - j : min(min(n, i) - j, (n - k) / (i - mn))); t++) {
                        if (i * mn < j * mn + k + i * t) break;
                        f[i][j + t][k + (i - mn) * t] = add(f[i][j + t][k + (i - mn) * t], mul(f[i - 1][j][k], inv[t]));
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++) ans = add(ans, f[n + 1][n][i]);
    }
    print(add(mul(ans, fac[n]), 1), '\n');
    return 0;
}