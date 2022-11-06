#include <cstdio>
#include <iostream>
#define MN 4010

const int mod = 998244353;
int n, m, k;
int f[MN][MN], g[MN][MN];
bool uf[MN], ug[MN];
int fac[MN], inv[MN];

void solve(int f[MN][MN], bool *uf, int n)
{
    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j > 0 && i > 1 && !uf[i] && !uf[i - 1]) f[i][j] = (f[i][j] + f[i - 2][j - 1]) % mod;
        }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    fac[0] = inv[0] = inv[1] = 1;
    for(int i = 1; i <= std::max(n, m); i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    for(int i = 2; i <= std::max(n, m); i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 1; i <= std::max(n, m); i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;

    int lf = n, lg = m;
    for(int i = 1; i <= k; i++)
    {
        int x1, y1, x2, y2; 
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        uf[x1] = uf[x2] = 1;
        ug[y1] = ug[y2] = 1;
        lf -= x1 == x2 ? 1 : 2;
        lg -= y1 == y2 ? 1 : 2;
    }
    
    solve(f, uf, n); solve(g, ug, m);
    
    int ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            if(lf - 2 * i - j >= 0 && lg - 2 * j - i >= 0)
                ans = (ans + 1ll * f[n][i] * g[m][j] % mod * fac[lg - 2 * j] % mod * inv[lg - 2 * j - i] % mod * fac[lf - 2 * i] % mod * inv[lf - 2 * i - j]) % mod;

    printf("%d\n", ans);
}