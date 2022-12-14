#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int n, test, pa[111][111], x, y, z, ft[111], dt[111][111];
bool u[111][111][111], used[111], fg, res;
char s[111];
queue<int> q;
vector<int> g[111];
int root(int id, int x)
{
	if (pa[id][x] != x) pa[id][x] = root(id, pa[id][x]);
	return pa[id][x];
}
void Union(int id, int x, int y)
{
	int rx = root(id, x), ry = root(id, y);
	if (rx == ry) return;
	pa[id][rx] = ry;
}
void dfs(int i, int fa, int rt, int d)
{
	dt[rt][i] = d;
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		if (to == fa) continue;
		dfs(to, i, rt, d + 1);
	}
}
bool chk()
{
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 0, i, 0);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				if ((dt[i][j] == dt[i][k]) ^ u[i][j][k]) return 0;
			}
		}
	}
	return 1;
}
int main()
{
    scanf("%d", &test);
    while(test--)
    {
		scanf("%d", &n); res = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				scanf("%s", s);
				for (int k = 1; k <= n; k++)
				{
					u[k][i][j] = s[k - 1] - '0';
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			pa[i][j] = j;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					if (u[i][j][k]) Union(i, j, k);
				}
			}
		}
		for (int i = 2; i <= n; i++)
		{
			bool f = 0;
			for (int j = 1; j < i; j++) 
			{
				if (root(1, j) == root(1, i)) f = 1;
			}
			if (f) continue;
			for (int j = 1; j <= n; j++) g[j].clear();
			memset(used, 0, sizeof(used));
			q.push(1); used[1] = 1; fg = 0; ft[1] = 0;
			while(!q.empty())
			{
				x = q.front(); q.pop();
				for (int k = 1; k <= n; k++)
				{
					if (x == 1) 
					{
						if (root(x, k) == root(x, i)) 
						{
							if (used[k]) fg = 1;
							else 
							{
								used[k] = 1;
								g[x].push_back(k);
								g[k].push_back(x);
								ft[k] = x;
								q.push(k);
							}
						}
					}
					else
					{
						if (root(x, k) == root(x, ft[x]) && k != ft[x]) 
						{
							if (used[k]) fg = 1;
							else 
							{
								used[k] = 1;
								g[x].push_back(k);
								g[k].push_back(x);
								ft[k] = x;
								q.push(k);
							}
						}
					}
				}
			}
			for (int j = 1; j <= n; j++)
			{
				if (!used[j]) fg = 1;
			}
			if (!fg)
			{
				if (chk())
				{
					res = 1;
					break;
				}
			}
		}
		if (res)
		{
			printf("Yes\n");
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < g[i].size(); j++)
				{
					if (i < g[i][j]) printf("%d %d\n", i, g[i][j]);
				}
			}
		}
		else
		{
			printf("No\n");
		}
    }	
	return Accepted;
}