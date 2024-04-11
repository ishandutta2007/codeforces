#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
#define ll long long
const int const1 = 998244353;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	gp_hash_table < int, ll >  dp1[(1 << n)], dp2[(1 << n)];
	int go_to[n];
	int cost[n][n];
	for(int i = 0; i < n; i++)
	{
		go_to[i]= 0;
		for(int j = 0; j < n; j++)
		{
			cost[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cost[b][a] = 1;
		go_to[a] |= (1 << b);
		go_to[b] |= (1 << a); 
	}
	dp1[0][(1 << n) - 1] = 1;
	dp2[0][(1 << n) - 1] = 0;
	int cnt[n];
	for(int i = 0; i < (1 << n) - 1; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cnt[j] = 0;
			for(int k = 0; k < n; k++)
			{
				if((1 << k) & i)
				{
					cnt[j] += cost[j][k];
				}
			}
		}
		int mask = 0;
		for(int j = 0; j < n; j++)
		{
			if(((1 << j) & i) == 0)
			{
				mask += (1 << j);
			}
		}
		for(auto it : dp1[i])
		{
				int ms = it.first;
				ll d = it.second % const1;
			int prefmask = 0;
			for(int j = 0; j < n; j++)
			{
				if(((1 << j) & ms))
				{
					prefmask += (1 << j);
					int maskto = (prefmask ^ ms) | (mask & go_to[j]);
					int masknxt = i + (1 << j);
					dp1[masknxt][maskto] += (d);
					dp2[masknxt][maskto] = (dp2[masknxt][maskto] + dp2[i][ms] + cnt[j] * d) % const1;
				}
			}
		}
	}
	cout << dp2[(1 << n) - 1][0];
	return 0;
}