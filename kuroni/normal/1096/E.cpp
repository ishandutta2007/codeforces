#include <iostream>
#include <cstdio>
using namespace std;

const int N = 6005, MOD = 998244353;

int p, s, r;
long long fct[N], inv[N], inv_fct[N];

void init()
{
    fct[0] = inv_fct[0] = 1;
    fct[1] = inv_fct[1] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        fct[i] = fct[i - 1] * i % MOD;
        inv_fct[i] = inv_fct[i - 1] * inv[i] % MOD;
    }
}

long long C(int n, int k, bool rev = false)
{
    if (n < k)
        return 0;
    if (!rev)
        return fct[n] * inv_fct[k] % MOD * inv_fct[n - k] % MOD;
    else
        return inv_fct[n] * fct[k] % MOD * fct[n - k] % MOD;
}

long long find_ans(int sum, int per, int low, int cur)
{
    if (sum < low * cur + per || cur > per)
        return 0;
    if (per == 0)
        return sum == low * cur;
    return (C(per, cur) * C(sum - low * cur - 1, per - 1) + MOD - find_ans(sum, per, low, cur + 1)) % MOD;
}

int main()
{
    init();
    scanf("%d%d%d", &p, &s, &r);
    s += p;
    long long nu = 0, de = C(s - r - 1, p - 1, true);
    for (int i = r + 1; i <= s; i++)
        for (int j = 0; j < p; j++)
            (nu += C(p - 1, j) * find_ans(s - i * (j + 1), p - (j + 1), i - 1, 0) % MOD * inv[j + 1]) %= MOD;
    printf("%lld", nu * de % MOD);
}