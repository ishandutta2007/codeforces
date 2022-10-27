#include <bits/stdc++.h>

using namespace std;
vector <vector <int> > g;
vector <vector <int> > pred;
vector <int> dist;
vector <int> tin, tout;
vector <int> h;
int timer = 0;
void dfs(int v, int p)
{
	tin[v] = timer++;
	for(int j = 0; j < g[v].size(); j++)
	{
		if(g[v][j] != p)
		{
			h[g[v][j]] = h[v] + 1;
			dist[g[v][j]] = h[g[v][j]];
			pred[g[v][j]][0] = v;
			dfs(g[v][j], v);
		}
	}
	tout[v] = timer++;
}
bool pr(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
	if(pr(a, b))
	{
		return a;
	}
	if(pr(b, a))
	{
		return b;
	}
	if(tin[a] < tin[b])
	{
		swap(a, b);
	}
	for(int i = 19; i >= 0; i--)
	{
		if(!pr(pred[a][i], b))
		{
			a = pred[a][i];
		}
	}
	return pred[a][0];
}
signed main(){
	int n, m;
	cin >> n >> m;
	int t= sqrt(n);
	tin.resize(n);
	tout.resize(n);
	g.resize(n);
	dist.resize(n, 1e9);
	h.resize(n);
	pred.resize(n, vector <int> (20));
	h[0] = 0;
	dist[0] = 0;
	pred[0][0] = 0;
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	dfs(0, -1);
	pred.resize(n, vector <int> (20));
	for(int i = 1; i < 20; i++){
		for(int j = 0; j < n; j++)
		{
			pred[j][i] = pred[pred[j][i - 1]][i - 1];
		}
	}
	vector <int> res;
	for(int i = 0; i < m; i++)
	{
		int type;
		cin >> type;
		int v;
		cin >> v;
		v--;
		if(type == 2)
		{
			int ans = dist[v];
			for(int j = 0; j < res.size(); j++)
			{
				int k = lca(res[j], v);
				ans = min(ans, h[v] - h[k] + h[res[j]] - h[k]);
			}
			cout << ans << "\n";
		}
		else
		{
			res.push_back(v);
		}
		if(res.size() % t == 0)
		{
			queue <int> Q;
			for(int i = 0; i < res.size(); i++){
				dist[res[i]] = 0;
				Q.push(res[i]);
			}
			res.clear();
			while(Q.size() > 0)
			{
				int v = Q.front();
				Q.pop();
				for(int j = 0; j < g[v].size(); j++)
				{
					if(dist[g[v][j]] > dist[v] + 1)
					{
						dist[g[v][j]] = dist[v] + 1;
						Q.push(g[v][j]);
 					}
				}
			}
		}
	}
	return 0;
}