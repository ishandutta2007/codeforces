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

const int N = 105, md = 998244353;

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

int f[N][N], c[N][N];
int b[N], l[N], r[N];
int n, big, sum = 1;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(l[i]), read(r[i]), b[++big] = l[i], b[++big] = r[i] + 1, sum = mul(sum, r[i] - l[i] + 1);
    sort(b + 1, b + big + 1); big = unique(b + 1, b + big + 1) - b - 1;
    for (int i = 1; i <= n; i++) l[i] = lower_bound(b + 1, b + big + 1, l[i]) - b, r[i] = lower_bound(b + 1, b + big + 1, r[i] + 1) - b;
    for (int i = 1; i < big; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            c[i][j] = 1ll * c[i][j - 1] * (b[i + 1] - b[i] + j - 1) % md * fpow(j, md - 2) % md;
        }
    }
    for (int i = 1; i <= big; i++) f[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = big - 1; j >= 1; j--) {
            for (int k = i; k >= 1; k--) {
                if (j < l[k] || r[k] <= j) break;
                f[i][j] = add(f[i][j], mul(f[k - 1][j + 1], c[j][i - k + 1]));
            }
            // fprintf(stderr, "f[%d][%d] = %d\n", i, j, f[i][j]);
            f[i][j] = add(f[i][j], f[i][j + 1]);
        }
    }
    print(mul(f[n][1], fpow(sum, md - 2)), '\n');
    return 0;
}