#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int s[maxn] , from[maxn] , to[maxn] , ans[maxn];

vector<int> adj[maxn];

bool visited[maxn];

void dfs(int v , int pe = -1)
{
	visited[v] = 1;

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!visited[u])
			dfs(u , e);
	}

	if(pe != -1)
	{
		if(from[pe] == v)
			ans[pe] = -s[v] , s[to[pe]] += s[v];
		else
			ans[pe] = s[v] , s[from[pe]] += s[v];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	for(int i = 0; i < n; i++)
		cin >> s[i] , sum += s[i];

	if(sum != 0)
		return cout << "Impossible" << endl , 0;

	int m;
	cin >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dfs(0);

	cout << "Possible" << endl;
	for(int i = 0; i < m; i++)
		cout << ans[i] << endl;

}