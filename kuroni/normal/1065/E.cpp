#include <iostream>
#include <cstdio>
using namespace std;

const int MOD = 998244353;

int m, n, s, pre = 0, cur;
long long ans = 1;

long long pw(int u, int p)
{
    long long ret = 1;
    for (int i = 31; i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (p >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

int main()
{
    scanf("%d%d%d", &m, &n, &s);
    while (n--)
    {
        scanf("%d", &cur);
        long long tmp = pw(s, cur - pre);
        tmp = (tmp + 1) * tmp % MOD * 499122177 % MOD;
        (ans *= tmp) %= MOD;
        pre = cur;
    }
    (ans *= pw(s, m - 2 * pre)) %= MOD;
    printf("%lld", ans);
}