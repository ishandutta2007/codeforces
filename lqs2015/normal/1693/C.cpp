#include <bits/stdc++.h>
using namespace std;
int x, y, n, m, dist[222222], deg[222222];
vector<int> g[222222];
priority_queue<pair<int, int> > pq;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		g[y].push_back(x);
		deg[x] ++;
	}
	pq.push(make_pair(0, n));
	for (int i = 1; i < n; i++) dist[i] = 1e9;
	while(!pq.empty())
	{
		x = pq.top().second; y = -pq.top().first;
		pq.pop();
		if (dist[x] != y) continue;
		for (int i = 0; i < g[x].size(); i++)
		{
			int to = g[x][i];
			deg[to] --;
			if (dist[to] > dist[x] + 1 + deg[to]) 
			{
				dist[to] = dist[x] + 1 + deg[to];
				pq.push(make_pair(-dist[to], to));
			}
		}
	}
	printf("%d\n", dist[1]);
	return 0;
}