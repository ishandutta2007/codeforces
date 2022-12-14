#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int test, n, a[1111][1111], p[1111][1111], ans;
bool u[1111][1111];
bool In(int x, int y)
{
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}
bool check()
{
	for (int i = 1; i <= n; i++) 
	{
		if (!p[n][i]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				u[i][j] = 0;
				p[i][j] = 0;
			}
		}
		ans = 0;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!p[i - 1][j])
				{
					u[i][j] = 1;
					ans ^= a[i][j];
					for (int k = 0; k < 4; k++)
					{
						if (In(i + dx[k], j + dy[k])) p[i + dx[k]][j + dy[k]] ^= 1;
					}
				}
			}
		}
		assert(check());
		printf("%d\n", ans);
	}
	return 0;
}