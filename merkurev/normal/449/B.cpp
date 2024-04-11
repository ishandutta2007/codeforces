#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;



const int maxn = 2e5;
vector <pair<int, int> > g[maxn];
int rail[maxn];
long long dist[maxn];
const long long inf = 1e18;


priority_queue <pair<long long, int> > qu;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		g[a].push_back(make_pair(b, c) );
		g[b].push_back(make_pair(a, c) );
	}
	int ans = 0;
	memset(rail, -1, sizeof rail);
	for (int i = 0; i < k; i++)
	{
		int s, c;
		scanf("%d%d", &s, &c);
		s--;
		if (rail[s] != -1)
			ans++;
		if (rail[s] == -1 || rail[s] > c)
			rail[s] = c;
	}
	for (int i = 0; i < n; i++)
	{
		if (rail[i] != -1)
			qu.push(make_pair(-rail[i], i) );
		dist[i] = inf;
	}

	dist[0] = 0;
	qu.push(make_pair(-dist[0], 0) );

	while (!qu.empty() )
	{
		long long d = -qu.top().first;
		int v = qu.top().second;
		qu.pop();
		if (d > dist[v] )
			continue;
		if (d == dist[v] && rail[v] != -1)
			ans++;
		if (d < dist[v] )
			dist[v] = d;
		
		for (int i = 0; i < g[v].size(); i++)
		{
			int nv = g[v][i].first;
			long long nd = d + g[v][i].second;
			if (nd < dist[nv] )
			{
				dist[nv] = nd;
				qu.push(make_pair(-dist[nv], nv) );
			}
		}
		dist[v] = -1;
	}

	printf("%d\n", ans);

	return 0;
}