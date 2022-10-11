#include <iostream>
#include <stdio.h>
using namespace std;

int f[105][105], n, m, a[105], k[105], tmp = 0;
bool chk = false;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &k[i]);
        tmp += k[i];
    }

    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = f[i - 1][j] + (int)(a[i] == j);

    for (int i = 1; i <= n - tmp + 1; i++)
    {
        chk = true;
        for (int j = 1; j <= m; j++)
            if (f[i + tmp - 1][j] - f[i - 1][j] != k[j])
            {
                chk = false;
                break;
            }
        if (chk)
        {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
	return 0;
}