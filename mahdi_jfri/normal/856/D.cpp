#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
const int maxb = 20;
vector<int> adj[maxn] , x[maxn];
int p[maxn][maxb] , st[maxn] , ft[maxn] , t , from[maxn] , to[maxn] , w[maxn] , h[maxn];
ll fen_dp[maxn] , fen_pd[maxn];

ll dp[maxn] , pd[maxn];

ll get_pd(int v)
{
	v = st[v];
	ll res = 0;
	for(v++; v > 0; v -= v & (-v))
		res += fen_pd[v];
	return res;
}
void update_pd(int v , ll val)
{
	for(v++; v < maxn; v += v & (-v))
		fen_pd[v] += val;
}

ll get_dp(int v)
{
	v = st[v];
	ll res = 0;
	for(v++; v > 0; v -= v & (-v))
		res += fen_dp[v];
	return res;
}
void update_dp(int v , ll val)
{
	for(v++; v < maxn; v += v & (-v))
		fen_dp[v] += val;
}

void set_dfs(int v)
{
	st[v] = ++t;
	for(auto u : adj[v])
	{
		p[u][0] = v;
		for(int i = 1; i < maxb; i++)
			p[u][i] = p[p[u][i - 1]][i - 1];
		h[u] = h[v] + 1;
		set_dfs(u);
	}
	ft[v] = t;
}
bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] <= ft[v];
}
int lca(int v , int u)
{
	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(p[v][i] , u))
			v = p[v][i];
	if(is_par(v , u))
		return v;
	return p[v][0];
}
void dfs(int v)
{
	for(auto u : adj[v])
		dfs(u) , pd[v] += dp[u];
	update_pd(st[v] , pd[v]);
	update_pd(ft[v] + 1 , -pd[v]);
	for(auto e : x[v])
	{
		ll a = 0 , b = 0;
		if(from[e] != v)
			a = get_pd(from[e]) - pd[v] - get_dp(from[e]);
		if(to[e] != v)
			b = get_pd(to[e]) - pd[v] - get_dp(to[e]);
		dp[v] = max(dp[v] , w[e] + a + b + pd[v]);
	}
	dp[v] = max(dp[v] , pd[v]);
	update_dp(st[v] , dp[v]);
	update_dp(ft[v] + 1 , -dp[v]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		adj[p].pb(i);
	}
	set_dfs(0);
	for(int i = 0; i < m; i++)
	{
		cin >> from[i] >> to[i] >> w[i];
		from[i]--;
		to[i]--;
		x[lca(from[i] , to[i])].pb(i);
	}
	dfs(0);
	cout << dp[0] << endl;
}