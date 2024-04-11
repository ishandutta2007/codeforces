#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
vector <vector <int> > dp;
vector <vector <int> > dp1;
vector <vector <int> > dp2;
vector <vector <int> > g;
int n, k;
void dfs(int v, int p = -1){
	vector <int> mass;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
			mass.push_back(to);
		}
	}
	if(mass.size() == 0)
	{
		dp[v][0] = 1;
		if(k != 0)
		{
		dp[v][k + 1] = 1;
		}
		return;
	}
	for(int i = 0; i < mass.size(); i++)
	{
		int to = mass[i];
		if(i == 0)
		{
			for(int j = 0; j <= 2 * k; j++)
			{
				dp2[j][j] = dp[to][j];
			}
		}
		else
		{
			for(int j = 0; j <= 2 * k; j++)
			{
				for(int d = j; d <= 2 * k; d++)
				{
					for(int p = 0; p <= 2 * k; p++)
					{
						int left = min(j, p);
						int right = max(d, p);
						dp2[left][right] += dp1[j][d] * dp[to][p] % const1;
						if(dp2[left][right] >= const1)
						{
							dp2[left][right] -= const1;
						}
					}
				}
			}
		}
		for(int j = 0; j <= 2 * k; j++)
		{
			for(int d = j; d <= 2 * k; d++)
			{
				dp1[j][d] = dp2[j][d];
				dp2[j][d] = 0;
			}
		}
	}
	for(int j = 0; j <= 2 * k; j++)
	{
		for(int d = j; d <= 2 * k; d++)
		{
			int left = j + 1;
			int right = d + 1;
			dp[v][0] += dp1[j][d];
			if(dp[v][0] >= const1)
			{
				dp[v][0] -= const1;
			}
			if(d <= k || k - (j + 1) >= d - k)
			{
				dp[v][left] += dp1[j][d];
				if(dp[v][left] >= const1)
				{
					dp[v][left] -= const1;
				}
			}
			else if(right != 2 * k + 1)
			{
				dp[v][right] += dp1[j][d];
				if(dp[v][right] >= const1)
				{
					dp[v][right] -= const1;
				}
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	g.resize(n);
	dp.resize(n, vector <int> (2 * k + 10, 0));
	dp1.resize(2 * k + 10, vector <int> (2 * k + 10, 0));
	dp2.resize(2 * k + 10, vector <int> (2 * k + 10, 0));
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	int ans = 0;
	for(int i = 0; i <= k; i++)
	{
		ans += dp[0][i];
		if(ans >= const1)
		{
			ans -= const1;
		}
	}
	cout << ans;
	return 0;
}