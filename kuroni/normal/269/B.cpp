#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[5005], b[5005], f[5005][5005], n, m, i, j, ans = 0;
float t;

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%f", a + i, &t);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            f[i][j] = max(f[i][j], max(f[i - 1][j], f[i][j - 1]));
        }
    printf("%d", n - f[n][n]);
}