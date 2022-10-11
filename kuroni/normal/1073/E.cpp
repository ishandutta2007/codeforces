#include <iostream>
#include <cstdio>
using namespace std;

const int MOD = 998244353, MAX = 19;

int k;
long long l, r, pw[MAX + 1], sum[1 << 10], cf[MAX][1 << 10], cg[MAX][1 << 10], sf[MAX][1 << 10], sg[MAX][1 << 10];

void init()
{
    cg[0][0] = cg[1][1] = 1;
    for (int i = 1; i < 10; i++)
    {
        cf[1][1 << i] = cg[1][1 << i] = 1;
        sf[1][1 << i] = sg[1][1 << i] = i;
    }
    for (int mask = 1; mask < (1 << 10); mask++)
        for (int i = 0; i < 10; i++)
            if (mask >> i & 1)
                sum[mask] += i;
    for (int i = 2; i < MAX; i++)
    {
        for (int mask = 1; mask < (1 << 10); mask++)
        {
            cf[i][mask] = cf[i - 1][mask] * __builtin_popcount(mask) % MOD;
            cg[i][mask] = cg[i - 1][mask] * __builtin_popcount(mask) % MOD;
            sf[i][mask] = (sf[i - 1][mask] * 10 * __builtin_popcount(mask) + sum[mask] * cf[i - 1][mask]) % MOD;
            sg[i][mask] = (sg[i - 1][mask] * 10 * __builtin_popcount(mask) + sum[mask] * cg[i - 1][mask]) % MOD;
            for (int j = 0; j < 10; j++)
                if (mask >> j & 1)
                {
                    (cf[i][mask] += cf[i - 1][mask ^ (1 << j)]) %= MOD;
                    (cg[i][mask] += cg[i - 1][mask ^ (1 << j)]) %= MOD;
                    (sf[i][mask] += sf[i - 1][mask ^ (1 << j)] * 10 + cf[i - 1][mask ^ (1 << j)] * j) %= MOD;
                    (sg[i][mask] += sg[i - 1][mask ^ (1 << j)] * 10 + cg[i - 1][mask ^ (1 << j)] * j) %= MOD;
                }
        }
    }
    pw[0] = 1;
    for (int i = 1; i < MAX; i++)
        pw[i] = pw[i - 1] * 10;
}

long long find_ans(long long u)
{
    if (u < 10)
        return u * (u + 1) / 2;
    int lim = 0;
    long long ans = 0;
    while (pw[lim] <= u)
        lim++;
    for (int mask = 1; mask < (1 << 10); mask++)
        if (__builtin_popcount(mask) <= k)
            for (int j = 1; j < lim; j++)
                (ans += sf[j][mask]) %= MOD;
    int cur = 0;
    for (int i = lim; i >= 1; i--)
    {
        int d = u / pw[i - 1] - u / pw[i] * 10;
        for (int j = (i == lim ? 1 : 0); j < d; j++)
        {
            int tmp = cur | (1 << j);
            for (int mask = 0; mask < (1 << 10); mask++)
                if (__builtin_popcount(tmp | mask) <= k)
                    (ans += sg[i - 1][mask] + (u / pw[i] * pw[i] + pw[i - 1] * j) % MOD * cg[i - 1][mask] % MOD) %= MOD;
        }
        cur |= (1 << d);
    }
    if (__builtin_popcount(cur) <= k)
        (ans += u) %= MOD;
    return ans;
}

int main()
{
    scanf("%lld%lld%d", &l, &r, &k);
    init();
    printf("%lld", (find_ans(r) - find_ans(l - 1) + MOD) % MOD);
}