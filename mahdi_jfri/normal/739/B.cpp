#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
const int maxb = 23;

vector<int> adj[maxn];

ll a[maxn] , w[maxn] , h[maxn] , p[maxn][maxb] , ans[maxn];

void dfs(int v)
{
	int tmp = v;
	for(int i = maxb - 1; i >= 0; i--)
		if(h[v] - h[p[tmp][i]] <= a[v])
			tmp = p[tmp][i];
	if(v)
	{
		ans[p[v][0]]++;
		if(tmp)
			ans[p[tmp][0]]--;
	}
	for(auto u : adj[v])
	{
		p[u][0] = v;
		for(int i = 1; i < maxb; i++)
			p[u][i] = p[p[u][i - 1]][i - 1];
		h[u] = h[v] + w[u];
		dfs(u);
		ans[v] += ans[u];
	}
}
int main()
{
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
		cout << ans[i] << " ";
	cout << endl;
}