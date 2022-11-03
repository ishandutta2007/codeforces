#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
const int maxb = 22;
ll a[maxn] , d[maxn] , w[maxn] , p[maxn][maxb] , x[maxn];
vector<int> adj[maxn];
void dfs(int v)
{
	if(d[v] <= a[v] && v)
		x[p[v][0]]++;
	else if(v)
	{
		int u = v;
		for(int i = maxb - 1; i >= 0; i--)
			if(d[v] - d[p[u][i]] <= a[v])
				u = p[u][i];
		x[p[v][0]]++;
		x[p[u][0]]--;
	}
	for(auto u : adj[v])
	{
		p[u][0] = v;
		for(int i = 1; i < maxb; i++)
			p[u][i] = p[p[u][i - 1]][i - 1];
		d[u] = d[v] + w[u];
		dfs(u);
		x[v] += x[u];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p >> w[i];
		p--;
		adj[p].pb(i);
	}
	dfs(0);
	for(int i = 0; i < n; i++)
		cout << x[i] << " ";
}