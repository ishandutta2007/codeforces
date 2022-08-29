#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;



vector <int> q[105], Q[105];
vector <int> V[105];

bool used[105];



void dfs(int v)
{
	int len = Q[v].size();
	used[v] = true;
	for (int i = 0; i < len; i++)
	{
		int nx = Q[v][i];
		if (used[nx] )
			continue;
		dfs(nx);
	}
}

int main()
{

	int n, m;
	scanf("%d%d", &n, &m);
	bool nonZero = false;
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int x;
			nonZero = true;
			scanf("%d", &x);
			x--;
			q[i].push_back(x);
			V[x].push_back(i);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int len = V[i].size();
		for (int j = 0; j < len; j++)
			for (int h = 0; h < len; h++)
			{
				int a = V[i][j], b = V[i][h];
				Q[a].push_back(b);
			}
	}
	int ans = 0;


	if (!nonZero)
		ans++;

	for (int i = 0; i < n; i++)
	{
		if (used[i] )
			continue;
		ans++;
		dfs(i);
	}
	printf("%d", ans - 1);


	return 0;
}