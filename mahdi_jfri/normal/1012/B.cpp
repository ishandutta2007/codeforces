#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e5 + 20;

vector<int> adj[maxn];

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;

	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , q;
	cin >> n >> m >> q;

	for(int i = 0; i < q; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;
		b += n;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	int res = 0;
	for(int i = 0; i < n + m; i++)
		if(!visited[i])
			dfs(i) , res++;

	cout << res - 1 << endl;
}