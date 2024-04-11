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

const int N = 3005, B = 11;

int f[N][N], g[N][N], a[N], cnt[N], pw[N], ans[N], tem[N];
int n, c;

int main() {
    read(n); read(c);
    if (c == 1) {
        static int fac[N], inv[N];
        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
        inv[n] = fpow(fac[n], md - 2);
        for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
        print(0, ' ');
        for (int i = 1; i <= n; i++) print(mul(fac[n], mul(inv[i], inv[n - i])), i == n ? '\n' : ' ');
        return 0;
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = add(pw[i - 1], pw[i - 1]);
    for (int i = 1; i <= n; i++) read(a[i]);
    if (c > B) {
        for (int i = 1; i <= n; i++) {
            memset(cnt, 0, sizeof(cnt));
            int cnt0 = c - 1, now = 1;
            for (int j = i - 1; j >= 1; j--) {
                if (a[j] != a[i]) {
                    if (!cnt[a[j]]) {
                        --cnt0;
                        ++cnt[a[j]];
                    } else {
                        now = mul(now, fpow(pw[cnt[a[j]]] - 1, md - 2));
                        ++cnt[a[j]];
                        now = mul(now, pw[cnt[a[j]]] - 1);
                    }
                }
                if (!cnt0) g[j][i] = now;
            }
        }
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i / c; j++) {
                if (!f[i][j]) continue;
                for (int k = i + 1; k <= n; k++) {
                    if (!g[i + 1][k]) continue;
                    f[k][j + 1] = add(f[k][j + 1], mul(f[i][j], g[i + 1][k]));
                }
            }
        }
        tem[n + 1] = 1;
        memset(cnt, 0, sizeof(cnt));
        int cnt0 = c, now = 1;
        for (int i = n; i >= 1; i--) {
            if (!cnt[a[i]]) {
                --cnt0;
                ++cnt[a[i]];
            } else {
                now = mul(now, fpow(pw[cnt[a[i]]] - 1, md - 2));
                ++cnt[a[i]];
                now = mul(now, pw[cnt[a[i]]] - 1);
            }
            if (cnt0) tem[i] = pw[n - i + 1];
            else tem[i] = sub(pw[n - i + 1], now);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i / c; j++) {
                ans[j] = add(ans[j], mul(f[i][j], tem[i + 1]));
            }
        }
        ans[0] = sub(ans[0], 1);
        for (int i = 0; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    } else {
        static int dp[2][1 << B][N];
        dp[0][0][0] = 1;
        int all = (1 << c) - 1;
        for (int i = 1; i <= n; i++) --a[i];
        for (int i = 1; i <= n; i++) {
            int now = (i & 1), pre = now ^ 1;
            for (int j = 0; j < (1 << c); j++) {
                memset(dp[now][j], 0, (i / c + 1) * 4);
            }
            for (int j = 0; j < (1 << c); j++) {
                for (int k = 0; k <= (i - 1) / c; k++) {
                    if (!dp[pre][j][k]) continue;
                    dp[now][j][k] = add(dp[now][j][k], dp[pre][j][k]);
                    if ((j | (1 << a[i])) == all) {
                        dp[now][0][k + 1] = add(dp[now][0][k + 1], dp[pre][j][k]);
                    } else {
                        dp[now][j | (1 << a[i])][k] = add(dp[now][j | (1 << a[i])][k], dp[pre][j][k]);
                    }
                }
            }
        }
        int now = (n & 1);
        for (int i = 0; i < (1 << c); i++) {
            for (int j = 0; j <= n / c; j++) {
                ans[j] = add(ans[j], dp[now][i][j]);
            }
        }
        ans[0] = sub(ans[0], 1);
        for (int i = 0; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}