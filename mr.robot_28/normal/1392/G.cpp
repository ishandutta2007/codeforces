#include<bits/stdc++.h>
using namespace std;
int get_mask(string s)
{
	int mask = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '1')
		{
			mask += (1 << i);
		}
	}
	return mask;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;
    vector <int > p(k);
    int c1= 0, c2 = 0;
    for(int i = 0; i < k; i++)
    {
    	if(s[i] == '1')
    	{
    		c1++;
		}
		if(t[i] == '1')
		{
			c2++;
		}
    	p[i] = i;
	}
    int dp[2][(1 << k)];
	for(int j = 0; j < (1 << k); j++)
	{
		dp[0][j] = 1e9;
		dp[1][j] = -1e9;
	}
	dp[0][get_mask(s)] = -1;
	dp[1][get_mask(t)] = -1;
    for(int i = 0; i < n; i++)
    {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	swap(p[x], p[y]);
    	string s1, t1;
    	s1 = s;
    	t1 = t;
    	for(int j = 0; j < k; j++)
    	{
    		s1[p[j]] = s[j];
    		t1[p[j]] = t[j];
		}
		dp[0][get_mask(s1)] = min(dp[0][get_mask(s1)], i);
		dp[1][get_mask(t1)] = i;
	}
	int ans = 0;
	int L = 0, R = 0;
	for(int mask = (1 << k) - 1; mask >= 0; mask--)
	{
		if(dp[1][mask] - dp[0][mask] >= m)
		{
			ans = max(ans, 2 * __builtin_popcount(mask) + k - c1 - c2);
			if(ans == 2 * __builtin_popcount(mask) + k - c1 - c2)
			{
				L = dp[0][mask] + 1;
				R = dp[1][mask];
			}
		}
		for(int j = 0; j < k; j++)
		{
			if((1 << j) & mask)
			{
				dp[0][mask ^ (1 << j)] = min(dp[0][mask ^ (1 << j)], dp[0][mask]);
				dp[1][mask ^ (1 << j)] = max(dp[1][mask ^ (1 << j)], dp[1][mask]);
			}
		}
	}
	cout << ans << "\n" << L + 1 << " " << R + 1;
    return 0;
}