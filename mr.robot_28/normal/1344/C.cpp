#include <bits/stdc++.h>
using namespace std;
vector <int> used;
vector <vector <int> > g;
void dfs(int v)
{
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(used[to] == 1)
		{
			cout << -1;
			exit(0);
		}
		if(used[to] == 0)
		{
			dfs(to);
		}
	}
	used[v] = 2;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	used.resize(n);
	g.resize(n);
	vector <vector <int> > g1(n);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[b].push_back(a);
		g1[a].push_back(b);
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
		}
	}
	vector <int> p(n, -1), p1(n, -1);
	for(int i = 0; i < n; i++)
	{
		if(p[i] == -1)
		{
			queue <int> q;
			q.push(i);
			p[i] = i;
			while(q.size() != 0)
			{
				int v = q.front();
				q.pop();
				for(int j = 0; j < g[v].size(); j++)
				{
					int to = g[v][j];
					if(p[to] == -1)
					{
						p[to] = i;
						q.push(to);
					}
				}
			}
		}
		if(p1[i] == -1)
		{
			queue <int> q;
			q.push(i);
			p1[i] = i;
			while(q.size() != 0)
			{
				int v  =q.front();
				q.pop();
				for(int j = 0; j < g1[v].size(); j++)
				{
					int to = g1[v][j];
					if(p1[to] == -1)
					{
						p1[to] = i;
						q.push(to);
					}
				}
			}
		}
	}
	vector <int> col(n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(p[i] >= i && p1[i] >= i)
		{
			ans++;
			col[i] = 1;
		}
		else
		{
			col[i] = 2;
		}
	}
	cout << ans << "\n";
	for(int i = 0; i < n; i++)
	{
		if(col[i] == 1)
		{
			cout << "A";
		}
		else
		{
			cout << "E";
		}
	}
	return 0; 
}