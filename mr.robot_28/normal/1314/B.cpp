#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e8;
int dp[2][1 << 17][2][2];
int v[1 << 17];
int merge(int u, int l, int up, int down)
{
	if(up < u)
	{
		return -inf;
	}
	if(up + down < u + l)
	{
		return -inf;
	}
	return u + l + (down != 0);
}
int funct(int ini, int t, int u, int l)
{
	if(t == 1)
	{
		int x = v[ini] + v[ini + 1];
		int ret = (v[ini] != 0) + (v[ini + 1] != 0);
		if(u && l)
		{
			return x >=2 ? ret + 3 : -inf;
		}
		if(!u && !l)
		{
			return ret + 2 * (x != 0) + (x > 1);
		}
		if(u)
		{
			return x ? ret + 1 + 2 * (x > 1) : -inf;
		}
		if(l)
		{
			return x ? ret + 2 + (x > 1) : -inf;
		}
	}
	int &ans = dp[t&1][ini][u][l];
	if(ans != -1)
	{
		return ans;
	}
	ans = -inf;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			for(int i1 = 0; i1 < 2; i1++)
			{
				for(int j1 = 0; j1 < 2; j1++)
				{
					ans = max(ans, funct(ini, t - 1, i, j) + funct(ini + (1 << (t - 1)), t - 1, i1, j1) + merge(u, l, i + i1, j + j1));
				}
			}
		}
	}
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
	{
		int x;
		cin >> x ;
		x--;
		v[x / 2]++;
	}
	int ans = 0;
	for(int t = 1; t < n; t++)
	{
		for(int ini = 0; ini + (1 << t) <= (1 << n); ini += (1 << t))
		{
			for(int i = 0; i < 2; i++)
			{
				for(int j = 0; j < 2; j++)
				{
					dp[t & 1][ini][i][j] = -1;
					funct(ini, t, i, j);
				}
			}
		}
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			ans = max(funct(0, n - 1, i, j) + (i || j), ans);
		}
	}
	cout << ans;
	return 0;
}