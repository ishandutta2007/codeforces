#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 1e5 + 20;
const int maxb = 22;
vector<int> adj[maxn] , height[maxn] , roots;
int d[maxn] , st[maxn] , ft[maxn] , now , p[maxn][maxb];
void dfs(int v)
{
	st[v] = ++now;
	height[d[v]].pb(st[v]);
	for(auto u : adj[v])
	{
		p[u][0] = v;
		for(int i = 1; i < maxb; i++)
			p[u][i] = p[p[u][i - 1]][i - 1];
		d[u] = d[v] + 1;
		dfs(u);
	}
	ft[v] = now;
}
int get(int v , int h)
{
	for(int i = 0; i < maxb; i++)
		if(bit(h , i))
			v = p[v][i];
	return v;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if(!p)
		{
			roots.pb(i);
			continue;
		}
		p--;
		adj[p].pb(i);
	}
	for(auto v : roots)
	{
		for(int i = 0; i < maxb; i++)
			p[v][i] = v;
		dfs(v);
	}
	int m;
	cin >> m;
	while(m--)
	{
		int v , h;
		cin >> v >> h;
		v--;
		if(h > d[v])
		{
			cout << 0 << " ";
			continue;
		}
		int u = get(v , h);
		int r = upper_bound(height[d[v]].begin() , height[d[v]].end() , ft[u]) - height[d[v]].begin();
		int l = lower_bound(height[d[v]].begin() , height[d[v]].end() , st[u]) - height[d[v]].begin();
		cout << r - l - 1 << " ";
	}
}