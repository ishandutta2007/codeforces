// living in a glasshouse

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e3 + 20;
const int maxk = 80;
const int mod = 998244353;

vector<int> adj[maxn];

int c[maxk][maxk] , ans1[maxk] , ans2[maxk];

int dp[maxn][maxk] , pd[maxn][maxk];

int sz[maxn];
bool picked[maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

inline void SetSize(int v , int p = -1)
{
	memset(dp[v] , 0 , sizeof dp[v]);
	memset(pd[v] , 0 , sizeof pd[v]);
	sz[v] = 1;
	for(auto u : adj[v])
		if(!picked[u] && u != p)
		{
			SetSize(u , v);
			sz[v] += sz[u];
		}
}

inline int FindCentroid(int v , int n , int p = -1)
{
	for(auto u : adj[v])
		if(!picked[u] && u != p && sz[u] * 2 > n)
			return FindCentroid(u , n , v);
	return v;
}

inline void CalDp(int v , int i , int p = -1 , bool is = 0)
{
	for(auto u : adj[v])
		if(!picked[u])
			mkay(dp[v][i] += dp[u][i - 1]);

	for(auto u : adj[v])
		if(!picked[u] && u != p)
			mkay(pd[v][i] += pd[u][i - 1]);

	if(!is && p != -1)
		mkay(pd[v][i] += pd[p][i - 1]);

	if(p != -1 && i == maxk - 1)
		for(int i = 0; i < maxk; i++)
			for(int j = 0; j < maxk; j++)
				mkay(ans1[i + j] += 1LL * pd[v][i] * dp[v][j] % mod);

	for(auto u : adj[v])
		if(!picked[u] && u != p)
			CalDp(u , i , v , (p == -1));
}

inline void solve(int v)
{
	SetSize(v);
	int n = sz[v];
	v = FindCentroid(v , n);

	dp[v][0] = pd[v][0] = 1;

	for(auto u : adj[v])
		if(!picked[u])
			pd[u][1] = 1;

	for(int i = 1; i < maxk; i++)
		CalDp(v , i);

	picked[v] = 1;

	for(int i = 0; i < maxk; i++)
		mkay(ans1[i] += dp[v][i]);

	for(auto u : adj[v])
		if(!picked[u])
			solve(u);
}

void dude(int n)
{
	memset(dp , 0 , sizeof dp);
	memset(pd , 0 , sizeof pd);
	memset(picked , 0 , sizeof picked);
	for(int i = 0; i < maxn; i++)
		adj[i].clear();

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	solve(0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n1 , n2 , k;
	cin >> n1 >> n2 >> k;

	dude(n1);
	swap(ans1 , ans2);
	dude(n2);

	for(int i = 0; i < maxk; i++)
		for(int j = 0; j <= i; j++)
		{
			if(!j || i == j)
				c[i][j] = 1;
			else
				mkay(c[i][j] = c[i - 1][j] + c[i - 1][j - 1]);
		}

	int res = 0;
	for(int i = 0; i <= k; i++)
		mkay(res += 1LL * ans1[i] * ans2[k - i] % mod * c[k][i] % mod);

	cout << res << endl;

}