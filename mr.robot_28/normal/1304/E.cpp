#include<bits/stdc++.h>
 
using namespace std;
//#define int long long
vector <int> h;
vector <vector <int> > g, pred;
vector <int> tin, tout;
int timer = 0;
void dfs(int v, int p = -1)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != p)
		{
			h[g[v][i]] = h[v] + 1;
			pred[g[v][i]][0] = v;
			dfs(g[v][i], v);
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
	for(int j = pred[0].size() - 1; j >= 0; j--)
	{
		if(!pr(pred[b][j], a))
		{
			b = pred[b][j];
		}
	}
	return pred[b][0];
}
int s(int a, int b)
{
	int lca1 = lca(a, b);
	return h[a] + h[b] - 2 * h[lca1];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	h.resize(n);
	tin.resize(n);
	tout.resize(n);
	int p = log2(n) + 1;
	pred.resize(n, vector <int> (p));
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	for(int i = 1; i < p; i++)
	{
		for(int j = 0; j < n; j++)
		{
			pred[j][i] = pred[pred[j][i - 1]][i - 1];
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		x--;
		y--;
		a--;
		b--;
		int len1 = s(a, x) + 1 + s(y, b);
		int len2 = s(a, y) + 1 + s(x, b);
		int len3 = s(a, b);
		int xy = lca(x, y);
		int len4 = s(a, x) + 2 + s(y, xy) + s(x, xy) + s(y, b);
		int len5 = s(a, y) + 2 + s(x, xy) + s(y, xy) + s(x, b);
		if(len1 <= k && len1 % 2 == k % 2)
		{
			cout << "YES\n";
		}
		else if(len2 <= k && len2 % 2 == k % 2)
		{
			cout << "YES\n";
		}
		else if(len3 <= k && len3 % 2 == k % 2)
		{
			cout << "YES\n";
		}
		else if(len4 <= k && len4 % 2 == k % 2)
		{
			cout << "YES\n";
		}
		else if(len5 <= k && len5 % 2 == k % 2)
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