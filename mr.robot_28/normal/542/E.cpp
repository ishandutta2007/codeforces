#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> used;
vector <vector <int> > g;
void dfs(int v, int p = -1, int col = 0)
{
	used[v] = col;
	for(int i = 0; i< g[v].size(); i++)
	{
		int to = g[v][i];
		if(used[to] == -1)
		{
			dfs(to, v, 1 - col);
		}
		else if(used[to] == used[v])
		{
			cout << -1;
			exit(0);
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	used.resize(n, -1);
	g.resize(n);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >>  a>> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
	{
		if(used[i] == -1)
		{
			dfs(i);
		}
	}
	vector <vector <int> > dist(n, vector <int> (n));
	vector <int> ans(n, 0);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			used[j] = 0;
		}
		queue <int> q;
		q.push(i);
		used[i] = 1;
		dist[i][i] = 0;
		int max1 = 0;
		while(q.size() != 0)
		{
			int v= q.front();
			q.pop();
			for(int j = 0; j < g[v].size(); j++)
			{
				int to = g[v][j];
				if(used[to] == 0)
				{
					used[to] = 1;
					dist[i][to] = dist[i][v] + 1;
					max1 = max(max1, dist[i][to]);
					q.push(to);
				}
			}
		}
		ans[i] = max1;
	}
	for(int i = 0;  i< n; i++)
	{
		used[i] = 0;
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			queue <int> q;
			int max1 = 0;
			q.push(i);
			used[i] = 1;
			while(q.size() != 0)
			{
				int v = q.front();
				q.pop();
				max1 = max(max1, ans[v]);
				for(int j = 0; j < g[v].size(); j++)
				{
					int to = g[v][j];
					if(!used[to])
					{
						used[to] = 1;
						q.push(to);
					}
				}
			}
			sum += max1;
		}
	}
	cout << sum;
	return 0;
}