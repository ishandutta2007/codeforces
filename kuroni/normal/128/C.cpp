#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 1e9 + 7;
int C[2005][2005], i, j, m, n, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (i = 0; i <= n || i <= m; i++)
    {
        C[i][0] = 1;
        for (j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    printf("%I64d\n", 1LL * C[m - 1][2 * k] * C[n - 1][2 * k] % mod);
}