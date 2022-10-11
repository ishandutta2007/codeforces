#include <cstdio>
#define mod 1000000007
using namespace std;

int i, j, l, n, k, f[2005][2005], ans = 0;

int main()
{
    scanf("%d%d", &n, &k);
    f[0][1] = 1;
    for (i = 1; i <= k; i++)
        for (j = 1; j <= n; j++)
            for (l = 1; l <= n / j; l++)
            {
                f[i][j * l] += f[i - 1][j];
                f[i][j * l] %= mod;
            }
    for (i = 1; i <= n; i++)
    {
        ans += f[k][i];
        ans %= mod;
    }
    printf("%d", ans);
}