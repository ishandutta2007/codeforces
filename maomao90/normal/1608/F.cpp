#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2010, P = 998244353;
int n, m, ans;
int fac[maxn], inv[maxn], a[maxn], l[maxn], r[maxn], f[2][maxn][maxn];

int C(int n, int m) {
    if (n < m) return 0;
    return (ll)fac[n] * inv[m] % P * inv[n - m] % P;
}

int main() {
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = (ll)fac[i - 1] * i % P;
    for (int i = 2; i < maxn; i++) inv[i] = (ll)(P - P / i) * inv[P % i] % P;
    for (int i = 1; i < maxn; i++) inv[i] = (ll)inv[i - 1] * inv[i] % P;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        l[i] = max(a[i] - m, 0), r[i] = min(a[i] + m, i);
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int p = (i & 1);
        for (int k = 0; k <= i - l[i]; k++) {
            for (int j = max(l[i] - r[i - 1] - 1, 0); j < l[i] - l[i - 1]; j++) {
                f[p][l[i]][k] = (f[p][l[i]][k] + f[p ^ 1][l[i] - j - 1][k + j]) % P;
            }
        }
        for (int j = l[i] + 1; j <= r[i]; j++) {
            for (int k = 0; k <= i - j; k++) {
                f[p][j][k] = (f[p][j - 1][k + 1] + f[p ^ 1][j - 1][k]) % P;
            }
        }
        for (int j = l[i - 1]; j <= r[i - 1]; j++) {
            for (int k = 0; k < i - j; k++) {
                if ((l[i] <= j) && (j <= r[i])) {
                    f[p][j][k] = (f[p][j][k] + (ll)(j + k) * f[p ^ 1][j][k]) % P;
                    f[p][j][k + 1] = (f[p][j][k + 1] + (ll)(k + 1) * f[p ^ 1][j][k]) % P;
                }
            }
        }
        for (int j = l[i - 1]; j <= r[i - 1]; j++) {
            for (int k = 0; k < i - j; k++) {
                f[p ^ 1][j][k] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            ans = (ans + (ll)C(n - i, j) * f[n & 1][i][j]) % P;
        }
    }
    printf("%d\n", ans);
    return 0;
}