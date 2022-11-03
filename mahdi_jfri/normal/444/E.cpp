#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e3 + 20;
int x[maxn] , from[maxn] , to[maxn] , w[maxn] , n , sx , weight , totalx , tver;
vector<int> adj[maxn];
bool visited[maxn];
void dfs(int v)
{
	totalx += x[v];
	tver++;
	visited[v] = 1;
	for(auto e : adj[v])
	{
		if(w[e] >= weight)
			continue;
		int u = from[e] + to[e] - v;
		if(!visited[u])
			dfs(u);
	}
}
bool check(int x)
{
	weight = x;
	memset(visited , 0 , sizeof visited);
	for(int i = 1; i <= n; i++)
		if(!visited[i])
		{
			totalx = 0;
			tver = 0;
			dfs(i);
			if(sx - totalx < tver)
				return 0;
		}
	return 1;
}
int main()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> from[i] >> to[i] >> w[i];
		adj[from[i]].pb(i);
		adj[to[i]].pb(i);
	}
	for(int i = 1; i <= n; i++)
		cin >> x[i] , sx += x[i];
	int l = 0 , r = 1e4 + 20;
	while(r - l > 1)
	{
		int m = (r + l) / 2;
		if(check(m))
			l = m;
		else
			r = m;
	}
	cout << l << endl;
}