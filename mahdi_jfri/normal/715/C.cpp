#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;
int mod;

vector<int> adj[maxn];

bool picked[maxn];

int wp[maxn] , sz[maxn] , t[maxn] , from[maxn] , to[maxn] , w[maxn] , num[maxn] , h[maxn] , now;

ll res;

unordered_map<int , int> mp[maxn];

int pw(int a , int b)
{
	if(!b)
		return 1;
	int x = pw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b & 1)
		x = 1LL * x * a % mod;

	return x;
}

void prepare()
{
	int tmp = mod , phi = mod;
	for(int i = 2; i * i <= tmp; i++)
		if(tmp % i == 0)
		{
			phi -= phi / i;
			while(tmp % i == 0)
				tmp /= i;
		}
	if(tmp > 1)
		phi -= phi / tmp;

	wp[maxn - 1] = pw(pw(10 , maxn - 1) , phi - 1);
	for(int i = maxn - 2; i >= 0; i--)
		wp[i] = 1LL * wp[i + 1] * 10 % mod;

	t[0] = 1;
	for(int i = 1; i < maxn; i++)
		t[i] = 1LL * t[i - 1] * 10 % mod;
}

void plant(int v , int p = -1)
{
	sz[v] = 1;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(!picked[u] && u != p)
		{
			h[u] = h[v] + 1;
			num[u] = (num[v] + t[h[u] - 1] * w[e]) % mod;
			plant(u , v);
			sz[v] += sz[u];
		}
	}
}

int cnt(int v , int n , int p = -1)
{
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(!picked[u] && u != p && sz[u] * 2 > n)
			return cnt(u , n , v);
	}
	return v;
}

void dfs(int v , int val , int p = -1)
{
	mp[now][num[v]] += val;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(!picked[u] && u != p)
			dfs(u , val , v);
	}
}

void get(int v , int num = 0 , int p = -1)
{
	int tmp = 1LL * ((-num + mod) % mod) * wp[h[v]] % mod;
	res += mp[now][tmp];

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(!picked[u] && u != p)
			get(u , (1LL * num * 10 + w[e]) % mod , v);
	}
}

void solve(int v)
{
	h[v] = 0;
	plant(v);
	v = cnt(v , sz[v]);

	num[v] = 0;
	h[v] = 0;
	picked[v] = 1;
	plant(v);
	now = v;
	dfs(v , 1);

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(!picked[u])
		{
			dfs(u , -1);
			get(u , w[e]);
			dfs(u , 1);
		}
	}

	mp[now][0]--;
	res += mp[now][0];

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(!picked[u])
			solve(u);
	}

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> mod;

	prepare();

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		w[i] %= mod;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	solve(0);

	cout << res << endl;

}