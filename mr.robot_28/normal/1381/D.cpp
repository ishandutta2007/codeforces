#include<bits/stdc++.h>
 
using namespace std;
vector <int> h, p, depth;
vector <vector <int> > g;
int len;
vector <vector<int> > mass1;
void dfs1(int v, int p)
{
	mass1[v].push_back(0);
	mass1[v].push_back(0);
	mass1[v].push_back(0);
	h[v] = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			depth[to] = depth[v] + 1; 
			dfs1(to, v);
			h[v] = max(h[v], h[to] + 1);
			mass1[v].push_back(1 + h[to]); 
		}
	}
}
void dfs2(int v, int p)
{
	sort(mass1[v].begin(), mass1[v].end());
	reverse(mass1[v].begin(), mass1[v].end());
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			mass1[to].push_back(1 + mass1[v][mass1[v][0] == 1 + h[to]]);
			dfs2(to, v);
		}
	}
}
int en;
bool dfs(int v, int pr = -1)
{
	h[v] = 0;
	bool flag1 = (v == en);
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != pr)
		{
			p[to] = v;
			if(dfs(to, v))
			{
				flag1 = true;
			}
			else
			{
				h[v] = max(h[v], h[to] + 1);
			}
		}
	}
	return flag1;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, u, v;
		cin >> n >> u >> v;
		u--;
		v--;
		en = v;
		bool flag = false;
		g.resize(n);
		h.resize(n);
		p.resize(n, -1);
		mass1.resize(n);
		depth.resize(n);
		for(int i = 0; i < n; i++)
		{
			h[i] = 0;
			depth[i] = 0;
			g[i].clear();
		}
		for(int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		depth[u] = 0;
		dfs1(u, -1);
		dfs2(u, -1);
		for(int i = 0; i < n; i++)
		{
			if(mass1[i][2] >= depth[v])
			{
				flag = true;
			}
			mass1[i].clear();
		}
		if(!flag)
		{
			cout << "NO\n";
			continue;
		}
		dfs(u,-1);
		vector <int> path;
		path.push_back(v);
		while(v != u)
		{
			v = p[v];
			path.push_back(v);
		}
		len = path.size();
		int l = 0, r = path.size() - 1;
		int l1 = h[path.back()], r1 = r - h[path[0]];
		while(l < r)
		{
			if(l < l1)
			{
				l++;
				r1 = min(r1, len - 1 - (h[path[l]] - l));
			}
			else if(r > r1)
			{
				r--;
				l1 = max(l1, h[path[r]] - (len - 1- r));
			}
			else
			{
				break;
			}
		}
		if(l == r)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}