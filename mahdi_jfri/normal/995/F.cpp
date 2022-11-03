#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e3 + 20;
const int mod = 1e9 + 7;

vector<int> adj[maxn];

int dp[maxn][maxn] , ans[maxn] , fac[maxn] , caf[maxn];

void mkay(int &a)
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
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

void dfs(int v)
{
	for(auto u : adj[v])
		dfs(u);

	for(int i = 1; i < maxn; i++)
	{
		dp[v][i] = 1;

		for(auto u : adj[v])
			dp[v][i] = 1LL * dp[v][i] * dp[u][i] % mod;

		mkay(dp[v][i] += dp[v][i - 1]);
	}
}

int c(int r , int s)
{
	if(r > s || r < 0)
		return 0;

	return (1LL * fac[s] * caf[r] % mod) * caf[s - r] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = pw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n , d;
	cin >> n >> d;

	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;

		adj[p].pb(i);
	}

	dfs(0);

	int cd = 1 , res = 0;
	for(int i = 1; i <= min(n , d); i++)
	{
		cd = 1LL * cd * (d - i + 1) % mod;
		cd = 1LL * cd * pw(i , mod - 2) % mod;

		ans[i] = dp[0][i];

		for(int j = 1; j < i; j++)
			mkay(ans[i] -= 1LL * ans[j] * c(j , i) % mod);

		mkay(res += 1LL * ans[i] * cd % mod);
	}

	cout << res << endl;
}