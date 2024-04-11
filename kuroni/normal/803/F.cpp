#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 1E5, MOD = 1E9 + 7;

int n, a, cnt[MAX + 1];
long long f[MAX + 1];

int pw(int a)
{
    if (a == 0)
        return 1;
    long long ret = pw(a >> 1);
    (ret *= ret) %= MOD;
    if (a & 1)
        (ret *= 2) %= MOD;
    return ret;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = 1; i <= MAX; i++)
        for (int j = 2 * i; j <= MAX; j += i)
            cnt[i] += cnt[j];
    for (int i = MAX; i >= 1; i--)
    {
        f[i] = pw(cnt[i]) - 1;
        for (int j = 2 * i; j <= MAX; j += i)
            (f[i] -= f[j]) %= MOD;
    }
    printf("%d", (f[1] + MOD) % MOD);
}