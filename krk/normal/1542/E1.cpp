#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 55;
const int Maxm = Maxn * Maxn;

int n, mod;
int C[Maxn][Maxn];
int fac[Maxn];
int perm[Maxn][Maxm];
int has[Maxm];
int sum[Maxm];
int res;

int main()
{
    scanf("%d %d", &n, &mod);
    if (mod == 1) { printf("0\n"); return 0; }
    perm[1][0] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < Maxm; j++)
            for (int z = 0; z <= j && z < i; z++)
                perm[i][j] = (perm[i][j] + perm[i - 1][j - z]) % mod;
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(fac[i - 1]) * i % mod;
    for (int z = 0; z < n; z++) {
        int ans = 0;
        int sz = n - z;
        fill(has, has + Maxm, 0);
        for (int i = 0; i < sz; i++) {
            sum[Maxm - 1] = has[Maxm - 1];
            for (int j = Maxm - 2; j >= 0; j--)
                sum[j] = (sum[j + 1] + has[j]) % mod;
            for (int j = 0; j < Maxm; j++) if (perm[sz - 1][j]) {
                int tot = i + j;
                ans = (ans + ll(sum[tot + 1]) * perm[sz - 1][j]) % mod;
            }
            for (int j = 0; j < Maxm; j++) if (perm[sz - 1][j]) {
                int tot = i + j;
                has[tot] = (has[tot] + perm[sz - 1][j]) % mod;
            }
        }
        res = (res + ll(C[n][z]) * fac[z] % mod * ans) % mod;
    }
    printf("%d\n", res);
    return 0;
}