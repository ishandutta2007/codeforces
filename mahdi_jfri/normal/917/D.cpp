#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;
const int mod = 1e9 + 7;

int dp[maxn][maxn][maxn] , sz[maxn] , tmp[maxn][maxn] , res[maxn] , c[maxn][maxn];

vector<int> adj[maxn];

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

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

void dfs(int v , int p = -1)
{
	sz[v] = 1;
	dp[v][0][1] = 1;
	for(auto u : adj[v])
		if(u != p)
		{
			dfs(u , v);

			for(int tv = 0; tv < sz[v]; tv++)
				for(int sv = 1; sv <= sz[v]; sv++)
					for(int tu = 0; tu < sz[u]; tu++)
						for(int su = 1; su <= sz[u]; su++)
						{
							ok(tmp[tv + tu + 1][sv + su] += 1LL * dp[v][tv][sv] * dp[u][tu][su] % mod);
							ok(tmp[tv + tu][sv] += 1LL * (1LL * dp[v][tv][sv] * dp[u][tu][su] % mod) * su % mod);
						}

			sz[v] += sz[u];

			for(int i = 0; i < sz[v]; i++)
				for(int j = 1; j <= sz[v]; j++)
					dp[v][i][j] = tmp[i][j] , tmp[i][j] = 0;
		}
}

int ans(int n , int x)
{
	if(x <= 2)
		return 1;
	return pw(n , x - 2);
}

int main()
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j <= i; j++)
		{
			if(!j || i == j)
				c[i][j] = 1;
			else
				ok(c[i][j] = c[i - 1][j] + c[i - 1][j - 1]);
		}

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);

	for(int i = 0; i < n - 1; i++)
		for(int j = 1; j <= n; j++)
			ok(res[i] += 1LL * dp[0][i][j] * j % mod);

	res[n - 1] = 1;

	for(int i = 0; i < n; i++)
		res[i] = 1LL * res[i] * ans(n , n - i) % mod;

	for(int i = n - 1; i >= 0; i--)
		for(int j = i + 1; j < n; j++)
			ok(res[i] -= 1LL * res[j] * c[j][i] % mod);

	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}