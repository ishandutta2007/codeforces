#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> adj[maxn] , c;
pair<int , int> a[maxn];
bool visited[maxn];
vector<vector<int> > ans;
void dfs(int v)
{
	c.pb(v);
	visited[v] = 1;
	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i].first , a[i].second = i;
	sort(a , a + n);
	for(int i = 0; i < n; i++)
		adj[a[i].second].pb(i) , adj[i].pb(a[i].second);
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			c.clear();
			dfs(i);
			ans.pb(c);
		}
	}
	cout << ans.size() << endl;
	for(auto x : ans)
	{
		cout << x.size() << " ";
		for(auto v : x)
			cout << v + 1 << " ";
		cout << endl;
	}
}