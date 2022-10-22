#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int Maxm = Maxn * Maxn;
const int nil = Maxn * (Maxn - 1) / 2;

int n, mod;
int C[Maxn][Maxn];
int fac[Maxn];
int dp[Maxn][Maxm];
int res;

int main()
{
    scanf("%d %d", &n, &mod);
    if (mod == 1) { printf("0\n"); return 0; }
    dp[0][nil] = 1;
    dp[0][nil + 1] = mod - 2;
    dp[0][nil + 2] = 1;
    for (int i = 0; i + 1 < Maxn; i++) {
        int delt = 0;
        int cur = 0;
        for (int j = 0; j < Maxm; j++) {
            delt = (delt + dp[i][j]) % mod;
            cur = (cur + delt) % mod;
            dp[i][j] = cur;
            if (j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            if (cur) {
                dp[i + 1][j - i] = (dp[i + 1][j - i] + cur) % mod;
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] - 2 * cur % mod + mod) % mod;
                dp[i + 1][j + i + 2] = (dp[i + 1][j + i + 2] + cur) % mod;
            }
        }
    }
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
        for (int a = 0; a < sz; a++)
            for (int b = a + 1; b < sz; b++)
                ans = (ans + dp[sz - 1][nil + a - b - 1]) % mod;
        res = (res + ll(C[n][z]) * fac[z] % mod * ans) % mod;
    }
    printf("%d\n", res);
    return 0;
}