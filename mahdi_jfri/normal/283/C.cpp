#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 3e2 + 20;
const int maxt = 1e5 + 20;
const int mod = 1e9 + 7;

int dp[maxt] , out[maxn] , in[maxn];
ll a[maxn] , b[maxn] , sum;

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int dfs(int v , ll s = 0)
{
	if(b[v])
	{
		cout << 0 << endl;
		exit(0);
	}
	b[v] = a[v] + s;
	ll k = 0;
	if(out[v] != -1)
		k = dfs(out[v] , b[v]);
	sum += k * a[v];
	return k + 1;
}

int main()
{
	ll n , q , t;
	cin >> n >> q >> t;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	memset(in , -1 , sizeof in);
	memset(out , -1 , sizeof out);
	for(int i = 0; i < q; i++)
	{
		int v , u;
		cin >> v >> u;
		v--;
		u--;
		out[v] = u;
		in[u] = v;
	}
	for(int i = 0; i < n; i++)
		if(in[i] == -1)
			dfs(i);
	
	for(int i = 0; i < n; i++)
		if(!b[i])
			return cout << 0 << endl , 0;

	t -= sum;
	if(t < 0)
		return cout << 0 << endl , 0;

	dp[0] = 1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j <= t; j++)
			if(b[i] <= j)
				ok(dp[j] += dp[j - b[i]]);

	cout << dp[t] << endl;
}