#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
bitset<1005> b[1005][1005];
int test, n, m, a[1111][1111];
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				b[i][j].reset();
			}
		}
		if ((n + m - 1) & 1)
		{
			printf("NO\n");
			continue;
		}
		if (a[1][1] == 1) b[1][1].set(1);
		else b[1][1].set(0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1) continue;
				b[i][j] = b[i - 1][j] | b[i][j - 1];
				if (a[i][j] == 1) b[i][j] <<= 1;
			}
		}
		if (b[n][m][(n + m - 1) >> 1]) printf("YES\n");
		else printf("NO\n");
	}
	return Accepted;
}