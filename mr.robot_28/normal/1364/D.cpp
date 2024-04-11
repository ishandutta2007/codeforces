#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> color;
void dfs(int v, int c, int p = -1)
{
	color[v] = c;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, 1 - c, v);
		}
	}
}
vector <int> h, pred;
vector <int> cycle;
int maxsize = 1e9;
void dfs1(int v, int p = -1)
{
	color[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		if(color[to] == 1)
		{
			maxsize = min(maxsize, h[v] - h[to] + 1);
		}
		else if(color[to] != 2)
		{
			pred[to] = v;
			h[to] = h[v] + 1;
			dfs1(to, v);
		}
	}
	color[v] = 2;
}
void dfs2(int v, int p = -1)
{
	color[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		if(color[to] == 1)
		{
			if(h[v] - h[to] + 1 == maxsize && cycle.size() == 0)
			{
				int w = v;
				while(w != to)
				{
					cycle.push_back(w);
					w = pred[w];
				}
				cycle.push_back(to);
			}
		}
		else if(color[to] != 2)
		{
			dfs2(to, v);
		}
	}
	color[v] =2;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    pred.resize(n);
    color.resize(n, -1);
    h.resize(n);
    for(int i = 0; i < m; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
	}
	if(m == n - 1)
	{
		dfs(0, 0);
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; i++)
		{
			if(color[i] == 0)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		cout << 1 << "\n";
		if(cnt1 >= (k + 1) / 2)
		{
			cnt1 = (k + 1) / 2;
			for(int i = 0; i < n; i++)
			{
				if(cnt1 > 0 && color[i] == 0)
				{
					cnt1--;
					cout << i  + 1 << " ";
				}
			}
		}
		else
		{
			cnt2 = (k + 1) / 2;
			for(int i = 0; i < n; i++)
			{
				if(cnt2 > 0 && color[i] == 1)
				{
					cnt2--;
					cout << i + 1 << " ";
				}
			}
		}
	}
	else
	{
		dfs1(0);
		for(int i = 0; i < n; i++)
		{
			color[i] = 0;
		}
		dfs2(0);
		if(maxsize <= k)
		{
			cout << 2 << "\n";
			cout << maxsize << "\n";
			for(int i = 0; i < cycle.size(); i++)
			{
				cout << cycle[i] + 1 << " ";
			}
		}
		else
		{
			int cnt = (k + 1) / 2;
			cout << 1 << "\n";
			for(int i = 0; i < cycle.size(); i += 2)
			{
				if(cnt > 0)
				{
					cout << cycle[i] + 1 << " ";
					cnt--;
				}
			}
		}
	}
    return 0;
}