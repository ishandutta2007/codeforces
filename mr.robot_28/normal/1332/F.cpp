#include <bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
vector <vector <vector <int> > > dp;
vector <vector <int> > g;
int summod(int a)
{
	while(a < 0)
	{
		a += const1;
	}
	return a;
}
void dfs(int v, int p = -1)
{
	int sum1 = 1;
	int sum2 = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
			sum1 = sum1 * (dp[to][1][0] + dp[to][0][1] + dp[to][0][0]) % const1;
			sum2 = sum2 * (dp[to][0][1] + dp[to][0][0]) % const1;
		}
	}
	dp[v][1][1] = sum1;
	dp[v][0][1] = summod(sum1 - sum2);
	sum1 = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			sum1 = sum1 * (dp[to][0][0] + dp[to][0][1] + dp[to][1][0] + dp[to][1][1]) % const1;
		}
	}
	dp[v][0][0] = sum1;
	dp[v][1][0] = sum1;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp.resize(n, vector <vector <int> > (2, vector <int> (2)));
	g.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	int ans =  (dp[0][0][1] + dp[0][0][0]) % const1;
	ans = (ans - 1 + const1) % const1;
	cout << ans;
    return 0;
}