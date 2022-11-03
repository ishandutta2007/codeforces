#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxa = 1e7 + 20;
const int maxb = 27;
const int maxprime = 664580 + 20;
const int mod = 1e9 + 7;

vector<int> adj[maxn];

int st[maxn] , ft[maxn] , now = -1 , par[maxn][maxb];

int a[maxn] , prime[maxa] , id[maxa];

int num[maxprime][maxb];

vector<pair<int , pair<int , int> > > query[maxn];

int ans[maxn];

int bpw(int a , int b)
{
	if(!b)
		return 1;

	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

void SetParDfs(int v)
{
	st[v] = ++now;

	for(auto u : adj[v])
		if(u != par[v][0])
		{
			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];

			SetParDfs(u);
		}

	ft[v] = now;
}

bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] <= ft[v];
}

int lca(int v , int u)
{
	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(par[v][i] , u))
			v = par[v][i];

	if(is_par(v , u))
		return v;

	return par[v][0];
}

void dfs(int v)
{
	vector<pair<pair<int , int> , int> > changes;

	{
		int x = a[v];

		while(x > 1)
		{
			int k = prime[x] , t = 0;
			while(x % k == 0)
				x /= k , t++;

			num[id[k]][t]++;
			changes.pb({{id[k] , t} , 1});
		}
	}

	for(auto shit : query[v])
	{
		int x = shit.first , i = shit.second.first;

		int res = 1;

		while(x > 1)
		{
			int k = prime[x] , t = 0;
			while(x % k == 0)
				x /= k , t++;

			int sum = 0;
			for(int i = 0; i < maxb; i++)
				sum += num[id[k]][i] * min(i , t);

			res = 1LL * res * bpw(k , sum) % mod;
		}

		if(shit.second.second == -1)
			res = bpw(res , mod - 2) , res = 1LL * res * res % mod;

		ans[i] = 1LL * ans[i] * res % mod;
	}

	for(auto u : adj[v])
		if(u != par[v][0])
			dfs(u);

	for(auto shit : changes)
		num[shit.first.first][shit.first.second]--;

}

int main()
{
	int shit = 0;
	for(int i = 2; i < maxa; i++)
		if(!prime[i])
		{
			id[i] = shit++;
			for(int j = i; j < maxa; j += i)
				prime[j] = i;
		}

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	SetParDfs(0);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int q;
	scanf("%d", &q);

	for(int i = 0; i < q; i++)
	{
		int v , u , x;
		scanf("%d%d%d", &v, &u, &x);
		v-- , u--;

		int c = lca(v , u);

		query[v].pb({x , {i , 1}});
		query[u].pb({x , {i , 1}});
		query[c].pb({x , {i , -1}});

		ans[i] = __gcd(a[c] , x);
	}

	dfs(0);

	for(int i = 0; i < q; i++)
		printf("%d\n" , ans[i]);

}