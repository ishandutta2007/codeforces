#include <bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	int MAX = 0;
	vector <pair <int,int> > dp(n);
	for(int i = 0; i < n;  i++)
	{
		if(i == 0)
		{
			dp[i] = {A[i], B[i]};
		}
		else if(i == 1)
		{
			dp[i].first = dp[i - 1].second + A[i];
			dp[i].second = dp[i - 1].first + B[i];
		}
		else
		{
			dp[i].first = dp[i - 1].second + A[i];
			dp[i].second = dp[i - 1].first + B[i];
			int k = max(dp[i - 2].first, dp[i - 2].second);
			if(dp[i].first < k + A[i])
			{
				dp[i].first = k + A[i];
			}
			if(dp[i].second < k + B[i])
			{
				dp[i].second = k + B[i];
			}
		}
		if(max(dp[i].first, dp[i].second) > MAX)
		{
			MAX = max(dp[i].first, dp[i].second);
		}
	}
	cout << MAX;
	return 0;
}