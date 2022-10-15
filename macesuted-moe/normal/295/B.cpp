#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

int dist[maxn][maxn], graph[maxn][maxn], del[maxn];
bool vis[maxn];
long long answer[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &dist[i][j]);
	for (int i = 1; i <= n; i++)
		scanf("%d", del + i);
	memset(graph, 0x3f, sizeof(graph));
	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;
	for (int tk = n; tk; tk--)
	{
		int k = del[tk];
		vis[k] = true;
		for (int i = 1; i <= n; i++)
			graph[i][k] = min(graph[i][k], dist[i][k]), graph[k][i] = min(graph[k][i], dist[k][i]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
				if (vis[i] && vis[j])
					answer[tk] += graph[i][j];
			}
	}
	for (int i = 1; i <= n; i++)
		printf("%lld ", answer[i]);
	puts("");
	return 0;
}