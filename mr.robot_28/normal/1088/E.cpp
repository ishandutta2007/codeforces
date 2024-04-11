#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
#define int long long
vector <int> A;
vector <vector <int> > G;
int ans = -1e9, k = 0;
vector <int> dp;
void dfs(int v, int pred, bool f)
{
	dp[v] = A[v];
	for(int i = 0; i < G[v].size(); i++)
	{
		if(G[v][i] != pred)
		{
			dfs(G[v][i], v, f);
			if(dp[G[v][i]] > 0)
			{
				dp[v] += dp[G[v][i]];
			}
		}
	}
	if(f)
	{
		ans = max(ans, dp[v]);
	}
	else if(dp[v] == ans)
	{
		dp[v] = 0;
		k++;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	A.resize(n);
	G.resize(n);
	dp.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		v--;
		u--;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	dfs(0, -1, 1);
	dfs(0, -1, 0);
	cout << ans * k << " " << k;
    return 0;
}