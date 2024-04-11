#include <bits/stdc++.h>
 
using namespace std;
#define int long long
bool cmp(pair <pair <int, int> , int> a, pair <pair <int, int> , int> b)
{
	return a.first.second < b.first.second;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector <pair <pair <int, int> , int> > a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i].first.first >> a[i].first.second;
			a[i].second = i + 1;
		}
		sort(a.begin(), a.end(), cmp);
		vector <vector <int> > dp(n + 1, vector <int> (k + 1, -1e18));
		vector <vector <int> > pred(n + 1, vector <int> (k + 1, -1));
		dp[0][0] = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j <= k; j++)
			{
				if(j + 1 <= k && dp[i - 1][j] + j * a[i - 1].first.second + a[i - 1].first.first >= dp[i][j + 1])
				{
					pred[i][j + 1] = 1;
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + j * a[i - 1].first.second + a[i - 1].first.first);
				}
				if(dp[i][j] < dp[i - 1][j] + (k - 1) * a[i - 1].first.second)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + (k - 1) * a[i - 1].first.second);
					pred[i][j] = 0;
				}
			}
		}
		int st = k;
		int i = n;
		if(dp[n][k - 1] > dp[n][k])
		{
			st = k - 1;
		}
		vector <int> ans1, ans2;
		while(i > 0)
		{
			if(pred[i][st] == 1){
				ans1.push_back(i);
				st--;
			}
			else
			{
				ans2.push_back(i);
			}
			i--;
		}
		reverse(ans1.begin(), ans1.end());
		cout << ans1.size() + 2 * ans2.size() << "\n";
		if(ans1.size() == k)
		{
		for(int i = 0; i < ans1.size() - 1; i++)
		{
			cout << a[ans1[i] - 1].second << " ";
		}
		}
		else
		{
			for(int i = 0; i < ans1.size(); i++)
			{
				cout << a[ans1[i] - 1].second << " ";
			}
		}
		for(int i = 0; i < ans2.size(); i++)
		{
			cout << a[ans2[i] - 1].second << " ";
			cout << -a[ans2[i] - 1].second << " ";
		}
		if(ans1.size() == k)
		{
			cout << a[ans1.back() - 1].second << " ";
		}
		cout << "\n";
	}
    return 0;
}