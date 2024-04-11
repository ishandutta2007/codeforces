#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;



const int maxn = 1e5 + 100;
vector <int> g[maxn];
bool used[maxn];
vector <int> ans;
int bit[maxn];

bool dfs(int v)
{
	bit[v] ^= 1;
	ans.push_back(v);
	used[v] = true;
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int nv = g[v][i];
		if (used[nv] )
			continue;
		bool x = dfs(nv);
		ans.push_back(v);
		bit[v] ^= 1;
		if (x)
		{
			ans.push_back(nv);
			ans.push_back(v);
			bit[v] ^= 1;
		}
	}
	return bit[v];
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &bit[i] );

	int x = 0;
	for (int i = 0; i < n; i++)
		if (bit[i] )
		{
			x = (dfs(i) ? 1 : 0);
			break;
		}
	for (int i = 0; i < n; i++)
	{
		if (bit[i] && !used[i] )
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d\n", (int) ans.size() - x);
	for (int i = x; i < (int) ans.size(); i++)
		printf("%d ", ans[i] + 1);




	return 0;
}