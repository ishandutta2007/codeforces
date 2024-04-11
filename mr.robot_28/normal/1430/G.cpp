#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <pair <int, int> > > g(n);
	vector <int> cnt(n), cnt1(n);
	int mask_to[(1 << n)];
	int dp[1 << n];
	int pred[1 << n];
	for(int i = 0; i < (1 << n); i++)
	{
		mask_to[i] = 0;
		dp[i] = 1e9;
		pred[i] = 0;
	}
	for(int i = 0; i<m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		cnt[y]++;
		cnt1[x]++;
		mask_to[1 << x] |= (1 << y);
 		g[x].push_back({y, w});
	}
	for(int mask = 0; mask <(1 << n); mask++)
	{
		for(int j = 0; j < n; j++)
		{
			if((mask & (1 << j)) == 0)
			{
				mask_to[mask | (1 << j)] |= mask_to[mask];
			}
		}
	}
	queue <int> q;
	for(int i = 0; i< n; i++)
	{
		if(cnt1[i] == 0)
		{
			q.push(i);
		}
	}
	int st_mask = 0;
	for(int i = 0; i < n; i++)
	{
		if(cnt[i] == 0)
		{
			st_mask |= (1 << i);
		}
	}
	dp[0] = 0;
	bool can[(1 << n)];
	for(int mask = 0; mask < (1 << n); mask++)
	{
		can[mask] = 1; 
		for(int j = 0; j < n; j++)
		{
			if(((1 << j) & mask) && (mask_to[1 << j] & mask))
			{
				can[mask] = 0;
			}
		}
	}
	for(int mask = 0; mask < (1 << n); mask = (mask + 1))
	{
		bool flag = 1;
		for(int j = 0; j < n; j++)
		{
			if(((1 << j) & mask) == 0 && (mask_to[1 << j] & mask) != 0)
			{
				flag = 0;
				break;
			}
		}
		if(!flag)
		{
			continue;
		}
//		cout << mask << "\n";
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			if((1 << j) & mask)
			{
				for(int k = 0; k < g[j].size(); k++)
				{
					int to = g[j][k].first;
					if(((1 << to) & mask) == 0)
					{
						sum += g[j][k].second;
					}
				}
			}
		}
		int mask1 = ((1 << n) - 1) ^ mask;
		mask1 = mask_to[mask] & mask1;
		for(int j = 0; j < n; j++)
		{
			if(((1 << j) & mask) == 0 && cnt[j] == 0)
			{
				mask1 |= (1 << j);
			}
		}
		//cout << mask << " " << mask1 << "\n";
		for(int mask2 = mask1; mask2 > 0; mask2 = (mask2 - 1) & mask1)
		{
			if(can[mask2])
			{
		//		cout << mask2 << "\n";
			}
			if(can[mask2] && dp[mask2 | mask] > dp[mask] + sum)
			{
		//		cout << mask << " " << mask2 << "\n";
				dp[mask2 | mask] = dp[mask] + sum;
				pred[mask2 | mask] = mask;
			}
		}
	}
	vector <int> ans(n);
	int st = 0;
	int end_mask = (1 << n) - 1;
	while(end_mask != 0)
	{
		int mask1 = end_mask ^ pred[end_mask];
	//	cout << mask1 << "\n";
		for(int i = 0; i < n; i++)
		{
			if((1 << i) & mask1)
			{
				ans[i] = st;
			}
		}
		st++;
		end_mask = pred[end_mask];
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}