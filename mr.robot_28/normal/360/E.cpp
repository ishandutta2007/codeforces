#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n, m, k, s1, s2,f;
	cin >> n >> m >> k >> s1 >> s2 >> f;
	s1--;
	s2--;
	f--;
	vector <vector <pair <int, int> > > g(n);
	vector <vector <pair <int, int> > > t(n);
	vector <pair <pair <int, int>, int> > e(k);
	vector <pair <int, int> > e1(k);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back({b, c});
	}
	for(int i = 0; i < k; i++)
	{
		int a, b, l, r;
		cin >> a >> b >> l >> r;
		a--;
		b--;
		e[i] = {{r, l}, r};
		e1[i] = {a, b};
		t[a].push_back({b, i});
	}
	vector <int> d1(n, 1e18), d2(n, 1e18);
	while(true)
	{
		for(int i = 0; i < n; i++)
		{
			d1[i] = d2[i] = 1e18;
		}
		set <pair <int, int> > s;
		d1[s1] = 0;
		d2[s2] = 0;
		s.insert({0, s1});
		while(s.size() > 0)
		{
			int v = s.begin() -> second;
			s.erase(s.begin());
			for(int i = 0; i < g[v].size(); i++){
				int to = g[v][i].first;
				int w = g[v][i].second;
				if(d1[to] > w + d1[v])
				{
					s.erase({d1[to], to});
					d1[to] = w + d1[v];
					s.insert({d1[to], to});
				}
			}
			for(int i = 0; i < t[v].size(); i++)
			{
				int to = t[v][i].first;
				int w = e[t[v][i].second].second;
				if(d1[to] > w + d1[v])
				{
					s.erase({d1[to], to});
					d1[to] = w + d1[v];
					s.insert({d1[to], to});
				}
			}
		}
		s.insert({0, s2});
		while(s.size() > 0)
		{
			int v = s.begin() -> second;
			s.erase(s.begin());
			for(int i = 0; i < g[v].size(); i++){
				int to = g[v][i].first;
				int w = g[v][i].second;
				if(d2[to] > w + d2[v])
				{
					s.erase({d2[to], to});
					d2[to] = w + d2[v];
					s.insert({d2[to], to});
				}
			}
			for(int i = 0; i < t[v].size(); i++)
			{
				int to = t[v][i].first;
				int w = e[t[v][i].second].second;
				if(d2[to] > w + d2[v])
				{
					s.erase({d2[to], to});
					d2[to] = w + d2[v];
					s.insert({d2[to], to});
				}
			}
		}
		bool flag = false;
		for(int i = 0; i < k; i++)
		{
			if(e[i].second == e[i].first.second)
			{
				continue;
			}
			if(d1[e1[i].first] < d2[e1[i].first])
			{
				e[i].second = e[i].first.second;
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	if(d1[f] < d2[f])
	{
		cout << "WIN\n";
		for(int i = 0; i < k; i++)
		{
			cout << e[i].second <<  " ";
		}
		return 0;
	}
	while(true)
	{
		for(int i = 0; i < n; i++)
		{
			d1[i] = d2[i] = 1e18;
		}
		set <pair <int, int> > s;
		d1[s1] = 0;
		d2[s2] = 0;
		s.insert({0, s1});
		while(s.size() > 0)
		{
			int v = s.begin() -> second;
			s.erase(s.begin());
			for(int i = 0; i < g[v].size(); i++){
				int to = g[v][i].first;
				int w = g[v][i].second;
				if(d1[to] > w + d1[v])
				{
					s.erase({d1[to], to});
					d1[to] = w + d1[v];
					s.insert({d1[to], to});
				}
			}
			for(int i = 0; i < t[v].size(); i++)
			{
				int to = t[v][i].first;
				int w = e[t[v][i].second].second;
				if(d1[to] > w + d1[v])
				{
					s.erase({d1[to], to});
					d1[to] = w + d1[v];
					s.insert({d1[to], to});
				}
			}
		}
		s.insert({0, s2});
		while(s.size() > 0)
		{
			int v = s.begin() -> second;
			s.erase(s.begin());
			for(int i = 0; i < g[v].size(); i++){
				int to = g[v][i].first;
				int w = g[v][i].second;
				if(d2[to] > w + d2[v])
				{
					s.erase({d2[to], to});
					d2[to] = w + d2[v];
					s.insert({d2[to], to});
				}
			}
			for(int i = 0; i < t[v].size(); i++)
			{
				int to = t[v][i].first;
				int w = e[t[v][i].second].second;
				if(d2[to] > w + d2[v])
				{
					s.erase({d2[to], to});
					d2[to] = w + d2[v];
					s.insert({d2[to], to});
				}
			}
		}
		bool flag = false;
		for(int i = 0; i < k; i++)
		{
			if(e[i].second == e[i].first.second)
			{
				continue;
			}
			if(d1[e1[i].first] <= d2[e1[i].first])
			{
				e[i].second = e[i].first.second;
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	if(d1[f] == d2[f])
	{
		cout << "DRAW\n";
		for(int i = 0; i < k; i++)
		{
			cout << e[i].second <<  " ";
		}
		return 0;
	}
	cout << "LOSE";
	return 0;
}