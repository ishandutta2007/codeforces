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

const int N = 405;

int ans[N], fac[N], inv[N], C[N], s[N][N];
int n, k;

inline int binom(int n, int m) {
    if (m < 0 || n < m) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 400; i++) fac[i] = mul(fac[i - 1], i), inv[i] = fpow(fac[i], md - 2);
    s[0][0] = 1;
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            for (int k = 2; k <= i; k++) {
                s[i][j] = add(s[i][j], mul(s[i - k][j - 1], mul(binom(i - 1, k - 1), fac[k - 1])));
            }
            // fprintf(stderr, "s[%d][%d] = %d\n", i, j, s[i][j]);
        }
    }
    read(n); read(k);
    if (n == 2) {
        for (int i = 1; i <= k; i++) print(1, i == k ? '\n' : ' ');
        return 0;
    }
    C[0] = 1;
    for (int i = 1; i <= 400; i++) C[i] = mul(C[i - 1], mul(n - i + 1, fpow(i, md - 2)));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i] = add(ans[i], mul(C[i + j], s[i + j][j]));
            // fprintf(stderr, "i = %d, j = %d, ans[i] = %d\n", i, j, ans[i]);
        }
    }
    ans[0] = 1;
    for (int i = 1; i <= k; i++) {
        if (i >= 2) ans[i] = add(ans[i], ans[i - 2]);
        print(ans[i], i == k ? '\n' : ' ');
    }
    return 0;
}