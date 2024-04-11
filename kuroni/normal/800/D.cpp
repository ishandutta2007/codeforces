#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000005, MAX = 1000000, DI = 7, MOD = 1E9 + 7;

int n, u, cnt[MAX], di[DI];
long long ans = 0, pw[N], f[MAX], g[MAX], _dp[MAX][DI], *dp[MAX];

void init()
{
    pw[0] = di[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * 2 % MOD;
    for (int i = 1; i < DI; i++)
        di[i] = di[i - 1] * 10;
}

void find_ans(int u)
{
    for (int mask = 1; mask < 64; mask++)
    {
        int pre = u;
        for (int i = 0; i < 6; i++)
            if (mask >> i & 1)
            {
                if (u / di[i] % 10 == 9)
                    goto br;
                else
                    pre += di[i];
            }
        if (__builtin_popcount(mask) & 1)
        {
            (f[u] += f[pre]) %= MOD;
            (g[u] += g[pre]) %= MOD;
            cnt[u] += cnt[pre];
        }
        else
        {
            (f[u] += MOD - f[pre]) %= MOD;
            (g[u] += MOD - g[pre]) %= MOD;
            cnt[u] -= cnt[pre];
        }
    br:
        continue;
    }
    dp[u] = _dp[u] + 1;
    dp[u][5] = ((f[u] * f[u] - g[u]) % MOD * pw[max(cnt[u] - 2, 0)] + g[u] * pw[max(cnt[u] - 1, 0)]) % MOD;
    for (int i = 4; i >= -1; i--)
    {
        dp[u][i] = dp[u][i + 1];
        if (u / di[i + 1] % 10 != 9)
            (dp[u][i] += MOD - dp[u + di[i + 1]][i + 1]) %= MOD;
    }
    ans ^= dp[u][-1] * u;
}

int main()
{
    init();
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &u);
        cnt[u]++;
        (f[u] += u) %= MOD;
        (g[u] += 1LL * u * u) %= MOD;
    }
    for (int i = MAX - 1; i >= 0; i--)
        find_ans(i);
    printf("%lld", ans);
}