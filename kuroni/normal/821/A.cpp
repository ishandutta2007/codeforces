#include <iostream>
#include <cstdio>
using namespace std;

int n, i, j, l, k, a[55][55];
bool chk;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        scanf("%d", &a[i][j]);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        if (a[i][j] != 1)
        {
            chk = false;
            for (k = 1; k <= n; k++)
            {
                if (chk)
                    break;
                for (l = 1; l <= n; l++)
                    if (a[i][k] + a[l][j] == a[i][j])
                {
                    chk = true;
                    break;
                }
            }
            if (!chk)
            {
                printf("No");
                return 0;
            }
        }
    printf("Yes");
    return 0;
}