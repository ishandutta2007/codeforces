#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> dist;
int n;
int bfs1(int v)
{
	for(int i = 0; i < n; i++)
	{
		dist[i] = 1e9;
	}
	dist[v] = 0;
	queue <int> q;
	q.push(v);
	int e = -1;
	while(q.size() != 0)
	{
		int w = q.front();
		q.pop();
		e = w;
		for(int i = 0; i < g[w].size(); i++)
		{
			int to = g[w][i];
			if(dist[to] == 1e9)
			{
				dist[to] = dist[w] + 1;
				q.push(to);
			}
		}
	}
	return e;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, da, db;
		cin >> n >> a >> b >> da >> db;
		a--;
		b--;
		dist.resize(n, 1e9);
		g.resize(n);
		for(int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int q = bfs1(0);
		int q1 = bfs1(q);
		int diam = dist[q1];
		q1 = bfs1(a);
		if(dist[b] <= da)
		{
			cout << "Alice\n";
		}
		else if(min(db, diam) >= 2 * da + 1)
		{
			cout << "Bob\n";
		}
		else
		{
			cout << "Alice\n";
		}
		for(int i = 0; i < n; i++)
		{
			g[i].clear();
		}
	}
	return 0;
}