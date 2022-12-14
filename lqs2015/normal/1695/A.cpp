#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, m, a[44][44], mx, ans;
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &m);
        mx = -2e9;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                mx = max(mx, a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mx == a[i][j])
                {
                    ans = max(i, n + 1 - i) * max(j, m + 1 - j);
                }
            }
        }
        printf("%d\n", ans);
    }
	return Accepted;
}