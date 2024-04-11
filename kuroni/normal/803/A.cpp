#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, k, i, j, a[105][105];

int main()
{
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &k);
    if (k > n * n)
    {
        printf("-1");
        return 0;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        if (a[i][j] == 0 && k >= 1 + (i != j))
        {
            a[i][j] = a[j][i] = 1;
            k -= 1 + (i != j);
        }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}