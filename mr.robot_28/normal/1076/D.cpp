#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector <vector <pair <pair <int, int>, int> > > g(n);
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		g[x].push_back({{y, w}, i});
		g[y].push_back({{x, w}, i});
	}
	vector <int> d(n, 1e18);
	d[0] = 0;
	set <pair <int, int> > e;
	e.insert({0, 0});
	vector <int> ans;
	vector <int> pr(n);
	while(k > 0 && e.size() > 0)
	{
		pair <int, int> v = *e.begin();
		e.erase(e.begin());
		if(v.second != 0)
		{
			k--;
			ans.push_back(pr[v.second]);
		}
		if(k == 0)
		{
			break;
		}
		for(int i = 0; i < g[v.second].size(); i++)
		{
			int to = g[v.second][i].first.first;
			int w = g[v.second][i].first.second;
			if(d[v.second] + w < d[to])
			{
				e.erase({d[to], to});
				d[to] = d[v.second] + w;
				pr[to] = g[v.second][i].second;
				e.insert({d[to], to}); 
			}
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] + 1 << " ";
	}
	return 0;
}