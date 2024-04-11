#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

bool visited[maxn] , bad[maxn] , Is[maxn];

int dp[maxn] , h[maxn] , from[maxn] , to[maxn] , n , m , shit[maxn];

vector<int> adj[maxn] , ba_adab[maxn];

void merge(int v , int u)
{
	if(ba_adab[u].size() > ba_adab[v].size())
		ba_adab[v].swap(ba_adab[u]);

	for(auto e : ba_adab[u])
		ba_adab[v].pb(e);
	ba_adab[u].clear();
}

void dfs(int v , int pe = -1)
{
	visited[v] = 1;

	for(auto e : adj[v])
		if(e != pe)
		{
			int u = from[e] ^ to[e] ^ v;
			if(visited[u])
			{
				if(h[u] < h[v])
				{
					dp[u]--;
					dp[v]++;
					ba_adab[v].pb(e);
				}
			}
			else
			{
				h[u] = h[v] + 1;
				dfs(u , e);
				merge(v , u);
				dp[v] += dp[u];
			}
		}
	if(pe != -1 && !dp[v])
		Is[pe] = 1;
	if(pe != -1 && dp[v] > 1)
	{
		for(auto e : ba_adab[v])
			if(min(h[from[e]] , h[to[e]]) < h[v])
				bad[e] = 1;
		ba_adab[v].clear();
	}
}

void plant(int v , int pe = -1)
{
	visited[v] = 1;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(!visited[u])
		{
			plant(u , e);
			shit[v] += shit[u];
		}
	}

	if(pe != -1 && shit[v] > 0)
		bad[pe] = 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);

	for(int i = 0; i < m; i++)
		if(bad[i])
		{
			int a = from[i] , b = to[i];
			if(h[a] > h[b])
				swap(a , b);
			shit[a]--;
			shit[b]++;
		}

	memset(visited , 0 , sizeof visited);
	for(int i = 0; i < n; i++)
		if(!visited[i])
			plant(i);

	vector<int> ans;

	for(int i = 0; i < m; i++)
	{
		if(!Is[i] && !bad[i])
			ans.pb(i);
	}

	cout << ans.size() << endl;
	for(auto e : ans)
		cout << e + 1 << " ";
	cout << endl;

}