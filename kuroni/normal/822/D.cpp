#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 1e9 + 7, maxn = 5e6;
const long long INF = 1e15;
int f[maxn + 5], n, i, j, t, l, r;
long long ans[maxn + 5], cur = 1, res = 0;

int main()
{
    ans[1] = 0;
    for (i = 2; i <= maxn; i++)
    {
        if (f[i] == 0)
        {
            f[i] = i;
            for (j = i; j <= maxn / i; j++)
                f[i * j] = i;
        }
        ans[i] = INF;
    }
    for (i = 2; i <= maxn; i++)
        for (j = i; j != 1; j /= f[j])
        ans[i] = min(ans[i], ans[i / f[j]] + 1LL * (f[j] - 1) * i / 2);
    for (i = 2; i <= maxn; i++)
        ans[i] %= mod;
    scanf("%d%d%d", &t, &l, &r);
    for (i = l; i <= r; i++)
    {
        res += cur * ans[i];
        res %= mod;
        cur *= t;
        cur %= mod;
    }
    printf("%I64d", res);
}