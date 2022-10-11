#include <iostream>
#include <cstdio>
using namespace std;

const int N = 55, S = 55;

int n, s;
long long ans = 0, a[N];
bool f[N][S];

bool chk(long long cur)
{
    for (int i = 1; i <= n; i++)
    {
        f[i][1] = ((a[i] & cur) == cur);
        for (int j = 2; j <= s && j <= i; j++)
        {
            f[i][j] = false;
            for (int k = j - 1; k <= i - 1; k++)
                if (f[k][j - 1] && ((a[i] - a[k]) & cur) == cur)
                {
                    f[i][j] = true;
                    break;
                }
        }
    }
    return f[n][s];
}

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
        a[i] += a[i - 1];
    }
    for (int i = 63; i >= 0; i--)
        if (chk(ans + (1LL << i)))
            ans += 1LL << i;
    printf("%lld", ans);
}