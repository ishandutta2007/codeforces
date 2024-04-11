#include <stdio.h>
#include <iostream>
#include <queue>
#define MAXN 55
using namespace std;

int n, m;
bool g[MAXN][MAXN], vis[MAXN];
struct bcj
{
	int f[MAXN];
	int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
	void uni(int a, int b){f[find(a)] = find(f[b]);}
}fus;

void bfs(int x)
{
	queue <int> q;
	q.push(x);
	vis[x] = true;
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		for(int i = 1; i <= n; i ++)
			if(g[x][i] && !vis[i])
			{
				vis[i] = true;
				q.push(i);
			}
	}
	return;
}
int init()
{
	int i, a, b;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; i ++)
	{
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = true;
	}
	return 0;
}
int solve()
{
	int i, cnt = 0;
	for(i = 1; i <= n; i ++)
		if(!vis[i])
		{
			bfs(i);
			cnt ++;
		}
	cout << (1LL << (n - cnt)) << endl;
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}