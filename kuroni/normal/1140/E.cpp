#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005, MOD = 998244353;

int n, k, a[N];
long long f[N][3], ans = 1;

long long dp(int u)
{
    int cnt = 0, st = a[u], en = 0;
    for (int i = u + 2; ; i += 2)
        if (a[i] == -1)
            ++cnt;
        else
        {
            en = a[i];
            break;
        }
    if (st == 0)
        swap(st, en);
    if (st == 0) // open
    {
        f[1][0] = k;
        for (int i = 2; i <= cnt; i++)
            f[i][0] = f[i - 1][0] * (k - 1) % MOD;
        return f[cnt][0];
    }
    else if (en == 0) // half-closed
    {
        f[0][0] = 1;
        for (int i = 1; i <= cnt; i++)
        {
            f[i][0] = f[i - 1][1];
            f[i][1] = (f[i - 1][0] * (k - 1) + f[i - 1][1] * (k - 2)) % MOD;
        }
        return (f[cnt][0] + f[cnt][1]) % MOD;
    }
    else if (st == en) // closed but same value
    {
        f[0][0] = 1;
        for (int i = 1; i <= cnt; i++)
        {
            f[i][0] = f[i - 1][1];
            f[i][1] = (f[i - 1][0] * (k - 1) + f[i - 1][1] * (k - 2)) % MOD;
        }
        return f[cnt][1];
    }
    else // closed and different value
    {
        f[0][0] = 1;
        for (int i = 1; i <= cnt; i++)
        {
            f[i][0] = (f[i - 1][1] + f[i - 1][2]) % MOD;
            f[i][1] = (f[i - 1][0] + f[i - 1][2]) % MOD;
            f[i][2] = ((f[i - 1][0] + f[i - 1][1]) * (k - 2) + f[i - 1][2] * (k - 3)) % MOD;
        }
        return (f[cnt][0] + f[cnt][2]) % MOD;
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n + 1; i++)
        scanf("%d", a + i);
    for (int i = 0; i <= n + 1; i++)
        if (a[i] != -1)
            (ans *= dp(i)) %= MOD;
    printf("%lld", ans);
}