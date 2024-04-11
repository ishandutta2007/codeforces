#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 200, MOD = 998244353;

// f : greater
// g : smaller
// h : equal

int n, a, cur = 1, pre = 0, f[2][205], g[2][205], h[2][205];

int main()
{
    f[pre][0] = 1;
    scanf("%d", &n);
    while (n--)
    {
        swap(cur, pre);
        for (int i = 1; i <= MAX; i++)
        {
            f[cur][i] = (f[cur][i - 1] + ((f[pre][i - 1] + g[pre][i - 1]) % MOD + h[pre][i - 1]) % MOD) % MOD;
            h[cur][i] = ((f[pre][i] + g[pre][i]) % MOD + h[pre][i]) % MOD;
        }
        for (int i = MAX; i >= 1; i--)
            g[cur][i] = (g[cur][i + 1] + (g[pre][i + 1] + h[pre][i + 1]) % MOD) % MOD;
        scanf("%d", &a);
        if (a != -1)
            for (int i = 1; i <= MAX; i++)
                if (i != a)
                    f[cur][i] = g[cur][i] = h[cur][i] = 0;
        f[cur][0] = 0;
    }
    int ans = 0;
    if (a == -1)
        for (int i = 1; i <= MAX; i++)
            (ans += (g[cur][i] + h[cur][i]) % MOD) %= MOD;
    else
        ans = (g[cur][a] + h[cur][a]) % MOD;
    printf("%d\n", ans);
}