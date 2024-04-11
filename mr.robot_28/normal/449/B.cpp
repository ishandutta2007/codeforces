#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, m ,k;
	cin >> n >> m >> k;
	vector <vector <pair <int, int> > > g(n);
	vector <int> d(n, 1e9);
	d[0] = 0;
	for(int i = 0; i < m; i++)
	{
		int u, v, x;
		cin >> u >> v >> x;
		g[u - 1].push_back({v - 1, x});
		g[v - 1].push_back({u - 1, x});
	}
	vector <pair <int, int> > r(k);
	for(int i = 0; i < k; i++)
	{
		cin >> r[i].first >> r[i].second;
		r[i].first--;
	}
	set <pair <int, int> > w;
	vector <int> cnt(n);
	w.insert({0, 0});
	while(w.size() != 0)
	{
		set <pair <int, int> > :: iterator it;
		it = w.begin();
		int v = it -> second;
		w.erase(it);
		if(v == 0)
		{
			for(int i = 0; i < k; i++)
			{
				if(r[i].second < d[r[i].first])
				{
					w.erase({d[r[i].first], r[i].first});
					d[r[i].first] = r[i].second;
					w.insert({d[r[i].first], r[i].first});
				}
			}
		}
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].first;
			if(d[to] > d[v] + g[v][i].second)
			{
				w.erase({d[to], to});
				d[to] = d[v] + g[v][i].second;
				w.insert({d[to], to});
			}	
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < g[i].size(); j++)
		{
			if(d[g[i][j].first] == d[i] + g[i][j].second)
			{
				cnt[g[i][j].first]++;
			}
		}
	}
	for(int i = 0; i < k; i++)
	{
		if(d[r[i].first] == r[i].second)
		{
			cnt[r[i].first]++;
		}
	}
	int ans = 0;
	for(int i = 0; i < k; i++)
	{
		if(cnt[r[i].first] > 1 || d[r[i].first] < r[i].second)
		{
			ans++;
			if(d[r[i].first] == r[i].second)
			{
			cnt[r[i].first]--;
		}
		}
	}
	cout << ans;
	return 0;
}