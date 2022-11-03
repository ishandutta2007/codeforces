#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;

vector<int> adj[maxn] , query[maxn];

int c[maxn] , limit[maxn] , ans[maxn];

unordered_map<int , int> mp[maxn] , pm[maxn];

void dfs(int v , int p = -1)
{
	mp[v][c[v]]++;
	pm[v][1]++;
	for(auto u : adj[v])
		if(u != p)
		{
			dfs(u , v);
			if(mp[u].size() > mp[v].size())
				mp[v].swap(mp[u]) , pm[v].swap(pm[u]);
			for(auto x : mp[u])
			{
				int k = mp[v][x.first];
				mp[v][x.first] += x.second;
				for(int i = 1; i <= x.second; i++)
					pm[v][k + i]++;
			}
		}
	for(auto q : query[v])
		ans[q] = pm[v][limit[q]];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	for(int i = 0; i < q; i++)
	{
		int v;
		cin >> v >> limit[i];
		v--;
		query[v].pb(i);
	}
	dfs(0);
	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
}