#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxb = 21;

int from[maxn] , to[maxn] , dp[maxn] , h[maxn];
int s[maxn] , t[maxn] , cmp1[maxn] , cmp2[maxn] , c = 1;
int p[maxn][maxb] , st[maxn] , ft[maxn] , id = -1;


int dp_back[maxn] , dp_cross[maxn];
vector<int> adj[maxn] , back_edge[maxn] , cross_edge[maxn];

bool hide[maxn] , visited[maxn];

void dfs_(int v , bool x , int* cmp , int pe = -1)
{
	cmp[v] = c;
	dp[v] = h[v];
	for(auto e : adj[v])
		if(e != pe && !hide[e])
		{
			int u = from[e] ^ to[e] ^ v;
			if(!cmp[u])
			{
				h[u] = h[v] + 1;
				dfs_(u , x , cmp , e);
				dp[v] = min(dp[v] , dp[u]);
			}
			else
				dp[v] = min(dp[v] , h[u]);
		}
	if(pe != -1 && dp[v] == h[v] && !x)
		hide[pe] = 1;
}

bool is_par(int v , int u)
{
	return (st[v] <= st[u] && st[u] <= ft[v]);
}

void dfs(int v , int par = -1)
{
	visited[v] = 1;
	st[v] = ++id;
	if(par == -1)
		for(int i = 0; i < maxb; i++)
			p[v][i] = v;
	for(auto u : adj[v])
		if(u != par)
		{
			p[u][0] = v;
			for(int i = 1; i < maxb; i++)
				p[u][i] = p[p[u][i - 1]][i - 1];
			dfs(u , v);
		}
	ft[v] = id;
}

void dfs_solve(int v , int par = -1)
{
	visited[v] = 1;
	if(par == -1)
		h[v] = 0;
	dp_cross[v] = dp_back[v] = h[v];
	for(auto u : adj[v])
		if(u != par)
		{
			h[u] = h[v] + 1;
			dfs_solve(u , v);
			dp_cross[v] = min(dp_cross[v] , dp_cross[u]);
			dp_back[v] = min(dp_back[v] , dp_back[u]);
		}
	for(auto u : cross_edge[v])
		dp_cross[v] = min(dp_cross[v] , h[u]);
	for(auto u : back_edge[v])
		dp_back[v] = min(dp_back[v] , h[u]);
	if(dp_back[v] < h[v] && dp_cross[v] < h[v])
	{
		cout << "No" << endl;
		exit(0);
	}
}

int lca(int v , int u)
{
	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(p[v][i] , u))
			v = p[v][i];
	if(is_par(v , u))
		return v;
	return p[v][0];
}

int main()
{
	// Wtf cf ?
	int n , m , q;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++)
	{
		cin >> from[i] >> to[i];
		from[i]--;
		to[i]--;
		adj[from[i]].pb(i);
		adj[to[i]].pb(i);
	}

	for(int i = 0; i < n; i++)
		if(!cmp1[i])
		{
			dfs_(i , 0 , cmp1);
			c++;
		}
	c = 1;
	for(int i = 0; i < n; i++)
		if(!cmp2[i])
		{
			dfs_(i , 1 , cmp2);
			c++;
		}

	for(int i = 0; i < n; i++)
		adj[i].clear();

	for(int i = 0; i < m; i++)
		if(cmp2[from[i]] != cmp2[to[i]])
		{
			adj[cmp2[from[i]]].pb(cmp2[to[i]]);
			adj[cmp2[to[i]]].pb(cmp2[from[i]]);
		}

	for(int i = 1; i < c; i++)
		if(!visited[i])
			dfs(i);

	for(int i = 0; i < q; i++)
	{
		cin >> s[i] >> t[i];
		s[i]--;
		t[i]--;
		if(cmp1[s[i]] != cmp1[t[i]])
		{
			cout << "No" << endl;
			return 0;
		}
		if(cmp2[s[i]] == cmp2[t[i]])
			i-- , q--;
		else
		{
			int x = lca(cmp2[s[i]] , cmp2[t[i]]);
			back_edge[cmp2[s[i]]].pb(x);
			cross_edge[cmp2[t[i]]].pb(x);
		}
	}

	memset(visited , 0 , sizeof visited);
	for(int i = 1; i < c; i++)
		if(!visited[i])
			dfs_solve(i);
	cout << "Yes" << endl;
}