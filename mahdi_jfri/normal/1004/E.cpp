#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> adj[maxn];

int from[maxn] , to[maxn] , w[maxn];
int Up[maxn] , Down[maxn] , k , dp[maxn] , L[maxn] , R[maxn];

void CalDown(int v , int p = -1)
{
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(u != p)
		{
			CalDown(u , v);

			Down[v] = max(Down[v] , Down[u] + w[e]);
		}
	}
}

void CalUp(int v , int p = -1)
{
	int mx = 0;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(u != p)
		{
			Up[u] = max(Up[v] + w[e] , mx + w[e]);
			L[u] = mx;
			mx = max(mx , Down[u] + w[e]);
		}
	}

	reverse(adj[v].begin() , adj[v].end());
	mx = 0;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(u != p)
		{
			Up[u] = max(Up[u] , mx + w[e]);
			R[u] = mx;
			mx = max(mx , Down[u] + w[e]);

			CalUp(u , v);
		}
	}
	reverse(adj[v].begin() , adj[v].end());
}

bool dfs(int v , int m , int p = -1)
{
	vector<int> tmp;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(u != p)
		{
			if(dfs(u , m , v))
				return 1;

			if(L[u] <= m && R[u] <= m)
				dp[v] = min(dp[v] , dp[u] + 1);

			if(Down[u] + w[e] > m)
				tmp.pb(u);
		}
	}

	if(tmp.empty())
		dp[v] = 1;

	if((int)tmp.size() > 2 || Up[v] > m)
		return 0;

	if(dp[v] <= k)
		return 1;

	if((int)tmp.size() == 2 && dp[tmp[0]] + dp[tmp[1]] + 1 <= k)
		return 1;

	return 0;
}

bool check(int m)
{
	memset(dp , 63 , sizeof dp);
	return dfs(0 , m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> k;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	CalDown(0);
	CalUp(0);

	int l = -1 , r = 1e9 + 20;

	while(r - l > 1)
	{
		int m = (l + r) / 2;

		if(check(m))
			r = m;
		else
			l = m;
	}

	cout << r << endl;
}