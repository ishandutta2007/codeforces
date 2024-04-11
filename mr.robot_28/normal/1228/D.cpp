#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <bool> used;
signed main()
{
	int n, m;
	cin >> n >> m;
	used.resize(n, false);
	g.resize(n);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	vector <int> pl(n, -1);
	for(int i = 0; i < g[0].size(); i++)
	{
		pl[g[0][i]] = 1;
	}
	int kl = -1;
	for(int i = 0; i < n; i++)
	{
		if(pl[i] == 1)
		{
			kl = i;
		}
	}
	if(kl == -1)
	{
		cout << -1;
		return 0;
	}
	vector <int> pl1(n, -1);
	for(int i = 0; i < g[kl].size(); i++)
	{
		pl1[g[kl][i]] = 2;
	}
	cnt1 = n - g[0].size();
	cnt2 = n - g[kl].size();
	cnt3 = n - cnt1 - cnt2;
	if(cnt1 == 0 || cnt2 == 0 || cnt3 <= 0)
	{
		cout << -1;
		return 0;
	}
	vector <int> color(n, -1);
	for(int i = 0; i < n; i++)
	{
		if(pl[i] == 1 && pl1[i] == 2)
		{
			color[i] = 3;
		}
		else if(pl[i] == 1)
		{
			color[i] = 2;
		}
		else
		{
			color[i] = 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(color[i] == 1)
		{
			if(g[i].size() != n - cnt1)
			{
				cout << -1;
				return 0;
			}
		}
		else if(color[i] == 2)
		{
			if(g[i].size() != n - cnt2)
			{
				cout << -1;
				return 0;
			}
		}
		else
		{
			if(g[i].size() != n - cnt3)
			{
				cout << -1;
				return 0;
			}
		}
		for(int j = 0; j < g[i].size(); j++)
		{
			if(color[g[i][j]] == color[i])
			{
				cout << -1;
				return 0;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << color[i] << " ";
	}
	return 0;
}