#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2005, K = 2005, MOD = 1E9 + 7;

int n, k;
long long dp[N][K], suf[K];
char s[N];

int main()
{
    scanf("%d %d\n%s", &n, &k, s + 1);
    dp[n + 1][0] = 1;
    for (int i = 1; i <= n; i++)
        s[i] -= 'a' - 1;
    suf[0] = s[n];
    for (int u = n; u >= 1; u--)
        for (int v = 0; v <= (n - u + 1) * (n - u + 2) / 2 && v <= k; v++)
        {
            long long &ret = dp[u][v] = suf[v];
            for (int i = u; i <= (u + n) / 2; i++)
            {
                int rem = (i - u + 1) * (n - i + 1), opo = n - (i - u);
                if (rem <= v)
                {
                    (ret += dp[i + 1][v - rem] * (26 - s[i]) % MOD) %= MOD;
                    if (opo != i)
                        (ret += dp[opo + 1][v - rem] * (26 - s[opo]) % MOD) %= MOD;
                }
                else
                    break;
            }
            (suf[v] += ret * (s[u - 1] - 1) % MOD) %= MOD;
        }
    printf("%lld", dp[1][k]);
}