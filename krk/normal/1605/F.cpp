#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 82;

int n, k, mod;
int fac[Maxn];
int inv[Maxn];
int C[Maxn][Maxn];
int pw2[Maxn * Maxn];
int total[Maxn][Maxn];
int good[Maxn][Maxn];
int bad[Maxn][Maxn];
int dis[Maxn][Maxn];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int getC(int n, int k)
{
    if (n <= 60 && k >= (1ll << ll(n))) return 0;
    int res = 1;
    for (int i = 1; i <= k; i++)
        res = ll(res) * ll((pw2[n] - i + mod) % mod) % mod * inv[i] % mod;
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &k, &mod);
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(i) * fac[i - 1] % mod;
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 1; i < Maxn; i++)
        inv[i] = Inv(i);
    pw2[0] = 1;
    for (int i = 1; i < Maxn * Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++) {
            dis[i][j] = getC(j, i);
            for (int j2 = 0; j2 < j; j2++)
                dis[i][j] = (dis[i][j] - ll(C[j][j2]) * dis[i][j2] % mod + mod) % mod;
        }
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++) {
            total[i][j] = 1;
            for (int z = 0; z < j; z++)
                total[i][j] = ll(total[i][j]) * (pw2[i] - 1 + mod) % mod;
            good[i][j] = total[i][j];
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++) {
            for (int i2 = 0; i2 < i; i2++) {
                if (i == n && i % 2 != 0 && i2 + 1 == i) break;
                for (int j2 = 0; j2 < j; j2++)
                    bad[i][j] = (bad[i][j] + ll(C[i][i2]) * C[j][j2] % mod * dis[i - i2][j - j2] % mod * fac[i - i2] % mod * pw2[(i - i2) * j2] % mod * good[i2][j2]) % mod;
            }
            good[i][j] = (total[i][j] - bad[i][j] + mod) % mod;
        }
    int res = 0;
    for (int j = 0; j <= k; j++)
        res = (res + ll(C[k][j]) * good[n][j]) % mod;
    printf("%d\n", res);
    return 0;
}