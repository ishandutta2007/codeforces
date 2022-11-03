#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> adj[maxn] , tree[maxn];
int centroid_visited[maxn] , subtree[maxn] , p[maxn] , t = 1 , ans[maxn];
bool picked[maxn];
void set_subtree(int v)
{
	centroid_visited[v] = t;
	subtree[v] = 1;
	for(auto u : adj[v])
		if(!picked[u] && centroid_visited[u] != t)
		{
			set_subtree(u);
			subtree[v] += subtree[u];
		}
}
int get_centroid(int v , int root)
{
	centroid_visited[v] = t;
	for(auto u : adj[v])
		if(!picked[u] && centroid_visited[u] != t && (2 * subtree[u] > subtree[root] || (2 * subtree[u] == subtree[root] && u > v)))
			return get_centroid(u , root);
	return v;
}
void centroid_dfs(int v)
{
	picked[v] = 1;
	for(auto u : adj[v])
		if(!picked[u])
		{
			t++;
			set_subtree(u);
			t++;
			int cent = get_centroid(u , u);
	//		tree[v].pb(cent);
			ans[cent] = ans[v] + 1;
			p[cent] = v;
			centroid_dfs(cent);
		}
}
void dfs(int v , int x = 0)
{
	ans[v] = x;
	for(auto u : tree[v])
		dfs(u , x + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	set_subtree(1);
	t++;
	centroid_dfs(get_centroid(1 , 1));
//	for(int i = 1; i <= n; i++)
//		cout << p[i] << " ";
	for(int i = 1; i <= n; i++)
		cout << (char)(ans[i] + 'A') << " ";
}