#include<bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> h(n);
	vector <int> dp(n, -1e9);
	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	dp[0] = 0;
	set <int> s;
	vector <pair <int, int> > mass1, mass2;
	for(int i = 0; i < n; i++)
	{
		s.insert(i);
		mass1.push_back({h[i], i});
		mass2.push_back({h[i], i});
	}
	sort(mass1.begin(), mass1.end());
	sort(mass2.begin(), mass2.end());
	reverse(mass2.begin(), mass2.end());
	vector <vector <int> > g(n);
	for(int i = 0; i < n - 1; i++)
	{
		g[i].push_back(i + 1);
	}
	for(int i = 0; i < mass1.size(); i++)
	{
		int ind = mass1[i].second;
		s.erase(ind);
		set <int> :: iterator it;
		it = s.upper_bound(ind);
		if(it != s.end() && it != s.begin())
		{
			int a = *it;
			it--;
			int b = *it;
			if(h[ind] < h[a] && h[ind] < h[b])
			{
				g[b].push_back(a);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		s.insert(i);
	}
	for(int i = 0; i < mass2.size(); i++)
	{
		int ind = mass2[i].second;
		s.erase(ind);
		set <int> :: iterator it;
		it = s.upper_bound(ind);
		if(it != s.end() && it != s.begin())
		{
			int a = *it;
			it--;
			int b = *it;
			if(h[ind] > h[a] && h[ind] > h[b])
			{
				g[b].push_back(a);
			}
		}
	}
	queue <int> q;
	q.push(0);
	vector <int> dist(n, 1e9);
	dist[0] = 0;
	while(q.size() != 0)
	{
		int v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if(dist[to] == 1e9)
			{
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}
	cout << dist[n - 1];
	return 0;
}