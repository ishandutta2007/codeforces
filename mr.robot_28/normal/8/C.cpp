# include <bits/stdc++.h>
using namespace std;

signed main()
{
	int x1, y1;
	cin >> x1 >> y1;
	int n;
	cin >> n;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	vector <int> dp(1 << n, 1e9);
	dp[0] = 0;
	vector <int> pred(1 << n, 0);
	for(int i = 0; i < (1 << n) - 1; i++)
	{
		int mask = i;
		int right = -1;
		for(int j = 0; j < n; ++j){
			if(mask % 2 == 0)
			{
				right = j;
				break;
			}
			mask = mask / 2;
		}
		if(dp[i | (1 << right)] > dp[i] + 2 * (A[right].first - x1) * (A[right].first - x1) + 2 * (A[right].second - y1) * (A[right].second - y1))
		{
			dp[i | (1 << right)] = dp[i] + 2 * (A[right].first - x1) * (A[right].first - x1) + 2 * (A[right].second - y1) * (A[right].second - y1);
			pred[i | (1 << right)] = i;
		}
		for(int j = right + 1; j < n; j++)
		{
			if(((1 << j) & i) == 0)
			{
				int dist = (A[right].first - x1) * (A[right].first - x1) + (A[right].second - y1) * (A[right].second - y1);
				dist += (A[j].first - x1) * (A[j].first - x1) + (A[j].second - y1) * (A[j].second - y1);
				dist += (A[j].first - A[right].first) * (A[j].first - A[right].first) + (A[j].second - A[right].second) * (A[j].second - A[right].second);
				if(dp[i | (1 << j) | (1 << right)] > dp[i] + dist)
				{
					dp[i | (1 << right) | (1 << j)] = dp[i] + dist;
					pred[i | (1 << right) | (1 << j)] = i;
				}
			}
		}
	}
	cout << dp[(1 << n) - 1] << "\n";
	int p = (1 << n) - 1;
	cout << 0 << " ";
	while(p != 0)
	{
		int u = p - pred[p];
		for(int j = n - 1; j >= 0; j--)
		{
			if(u >= (1 << j))
			{
				cout << j + 1 << " ";
				u -= (1 << j);
			}
		}
		cout << 0 << " ";
		p = pred[p];
	}
	return 0;
}