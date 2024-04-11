#include<bits/stdc++.h>
using namespace std;
const int N = 410;
int n, q, p, t[N][N], fac[N], s[N][N];
inline int Qmi(int x, int y = p - 2) {
    int ans = 1;
    for (; y; y >>= 1, x = 1ll * x * x % p) if (y & 1) ans = 1ll * ans * x % p;
    return ans;
}
inline void Inverse() {
    for (int i = 1; i <= n; ++i) s[i][i] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!t[i][i]) {
            for (int j = i + 1; j <= n; ++j) if (t[j][i]) {
                for (int k = 1; k <= n; ++k) {
                    swap(t[i][k], t[j][k]);
                    swap(s[i][k], s[j][k]);
                }
                break;
            }
            assert(t[i][i]);
        }
        int qu = Qmi(s[i][i]);
        for (int j = 1; j <= n; ++j) {
            t[i][j] = 1ll * t[i][j] * qu % p;
            s[i][j] = 1ll * s[i][j] * qu % p;
        }
        for (int j = i + 1; j <= n; ++j) {
            int qu = t[j][i];
            for (int k = 1; k <= n; ++k) {
                t[j][k] = (t[j][k] - 1ll * t[i][k] * qu) % p;
                s[j][k] = (s[j][k] - 1ll * s[i][k] * qu) % p;
            }
        }
    }
}
inline void Debug() {
    int ans[100][100];
    memset(ans, 0, sizeof ans);
    puts("Check");
    for (int i = 1; i <= n; ++i) t[i][1] = fac[i];
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= i; ++j)
            for (int k = 0; k <= i - j; ++k)
                t[i][j] = (t[i][j] + 1ll * fac[k + 1] * t[i - k - 1][j - 1]) % p;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                ans[i][k] = (ans[i][k] + 1ll * t[i][j] * s[j][k]) % p;
    puts("ans[][]");
    for (int i = 1; i <= n; puts(""), ++i) 
        for (int j = 1; j <= n; ++j)
            printf("%d ", ans[i][j]);

}
int main() {
    scanf("%d%d", &q, &p);
    n = 400;
    fac[0] = 1; for (int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % p;
    for (int i = 1; i <= n; ++i) t[i][1] = fac[i];
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= i; ++j)
            for (int k = 0; k <= i - j; ++k)
                t[i][j] = (t[i][j] + 1ll * fac[k + 1] * t[i - k - 1][j - 1]) % p;
    Inverse();
    for (int i = 1, x; i <= q; ++i) {
        scanf("%d", &x);
        if (x == 2) { puts("2"); continue; }
        int ans = (-s[x][1] + (~x & 1 ? -2 : 2)) % p;
        if (ans < 0) ans += p;
        printf("%d\n", ans);
    }
    return 0;
}