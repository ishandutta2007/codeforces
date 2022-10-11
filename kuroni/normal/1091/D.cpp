#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000005, MOD = 998244353;

int n;
long long fct[N], f[N];

int main()
{
    scanf("%d", &n);
    fct[1] = 1; f[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        fct[i] = fct[i - 1] * i % MOD;
        f[i] = (f[i - 1] + fct[i - 1] - 1) * i % MOD;
    }
    printf("%lld\n", (f[n] + fct[n]) % MOD);
}