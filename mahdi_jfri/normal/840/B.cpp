#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;
vector<pair<int , int> > adj[maxn];
ll a[maxn] , x[maxn] , pe[maxn];
bool visited[maxn] , is[maxn];
void dfs(int v)
{
	visited[v] = 1;
	if(a[v] != adj[v].size() % 2 && a[v] != -1)
		x[v]++;
	for(auto u : adj[v])
		if(!visited[u.first])
		{
			pe[u.first] = u.second;
			dfs(u.first);
			x[v] += x[u.first];
		}
}
int main()
{
	int n , m , node = -1;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] == -1)
			node = i;
	}
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb({--b , i});
		adj[b].pb({a , i});
	}
	ll z = 0;
	for(int i = 0; i < n; i++)
		if(node == -1 && a[i] != adj[i].size() % 2)
			z++;
	if(node == -1 && z % 2 == 1)
	{
		cout << -1;
		return 0;
	}
	if(node == -1)
		node = 0;
	dfs(node);
	for(int i = 0; i < n; i++)
		if(node != i && x[i] % 2 == 1)
			is[pe[i]] = 1;
	vector<int> ans;
	for(int i = 0; i < m; i++)
		if(!is[i])
			ans.pb(i);
	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x + 1 << " ";
}