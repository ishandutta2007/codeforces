#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int n, m, x, y, z, id;
long long dist[666][666], pre[666][666], suf[666][666], d[666], mn;
bool u[666];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		dist[i][j] = 1e14;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		dist[x][y] = z;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0) pre[i][j] = dist[i][j];
			else pre[i][j] = min(pre[i][j - 1] + 1, dist[i][j]);
		}
		suf[i][n] = 1e14;
		for (int j = n - 1; j >= 0; j--)
		{
			suf[i][j] = min(suf[i][j + 1], dist[i][j] + n - 1 - j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[j] = 1e14;
		}
		d[i] = 0;
		memset(u, 0, sizeof(u));
		for (int j = 0; j < n; j++)
		{
			mn = 1e14; id = -1;
			for (int k = 0; k < n; k++)
			{
				if (!u[k] && d[k] < mn)
				{
					mn = d[k];
					id = k;
				}
			}
			u[id] = 1;
			x = d[id] % n;
			for (int k = 0; k < n; k++)
			{
				if (u[k]) continue;
				y = k - x + n;
				if (y >= n) y -= n;
				d[k] = min(d[k], d[id] + min(pre[id][y], suf[id][y + 1] + (y + 1)));
			}
		}
		for (int j = 0; j < n; j++) printf("%lld ", d[j]);
		printf("\n");
	}
	return Accepted;
}