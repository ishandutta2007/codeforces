#include <bits/stdc++.h>
                  
using namespace std;

signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <pair <int, int> > > intervals(n);
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			intervals[i].push_back({l, r});
		}
	}
	for(int i = 0; i < n; i++)
	{
		sort(intervals[i].begin(), intervals[i].end());
	}
	vector <int> iter(n);
	vector <vector <int> > dp(m, vector <int> (m, -1e9));
	for(int len = 1; len <= m; len++)
	{
		for(int i = 0; i + len <= m; i++)
		{
			for(int x = 0; x < n; x++)
			{
				iter[x] = 0;
				while(intervals[x][iter[x]].second < i)
				{
					iter[x]++;
				}
			}
			for(int j = i; j < i + len; j++)
			{
				int sum = 0;
				for(int x = 0; x < n; x++)
				{
					if(intervals[x][iter[x]].second < j)
					{
						iter[x]++;
					}
					if(intervals[x][iter[x]].first >= i && intervals[x][iter[x]].second <= i + len - 1)
					{
						sum++;
					}
				}
				sum = sum * sum;
				if(j != i)
				{
					sum += dp[i][j - 1];
				}
				if(j != i + len - 1)
				{
					sum += dp[j + 1][i + len - 1];
				}
				dp[i][i + len - 1] = max(dp[i][i + len - 1], sum);
			}
		}
	}
	cout << dp[0][m - 1];
	return 0;
}