#include<bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> dist(n, 1e9), go(n, -1);
	vector <vector <pair <int, int> > > g(n);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[b].push_back({a, c});
	}
	set <pair <int, int> > s;
	s.insert({0, n - 1});
	dist[n - 1] = 0;
	while(s.size() != 0)
	{
		int v = s.begin() -> second;
		s.erase(s.begin());
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].first;
			int c = g[v][i].second;
			if(dist[to] > dist[v] + 1)
			{
				if(go[to] == -1)
				{
					go[to] = c ^ 1;
				}
				if(go[to] == c)
				{
					s.erase({dist[to], to});
					dist[to] = dist[v] + 1;
					s.insert({dist[to], to});
				}
			}
		}
	}
	if(dist[0] == 1e9)
	{
		dist[0] = -1;
	}
	cout << dist[0] << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << max(go[i], 0);
	}
	return 0;
}