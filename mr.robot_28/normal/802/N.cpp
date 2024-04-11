# include <bits/stdc++.h>
using namespace std;
#define int long long
pair <int, int> dp[2500][2500];
pair <int, int> solve(vector <int> &a, vector <int> &b, int fine)
{
	int n = a.size();
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			dp[i][j] = {-1e18, 1e9};
		}
	}
	for(int i = 0; i < n; ++i)
	{
		dp[0][i] = {0, 0};
	}
	pair <int, int> ans = make_pair(0, 0);
	for(int i = 0; i < n; i++)
	{
		pair <int, int> tut = make_pair(0, 0);
		dp[i + 1][0] = dp[i][0];
		for(int j = 0; j < n; j++)
		{
			dp[i + 1][j + 1] = dp[i][j + 1];
			if(j >= i)
			{
				pair <int, int> var = tut;
				if(a[i] + b[j] + fine > 0)
				{
					var.first += a[i] + b[j] + fine;
					var.second--;
				}
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], var);
				ans = max(ans, dp[i + 1][j + 1]);
			}
			tut = max(tut, dp[i][j + 1]);
		}
	}
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, n;
	cin >> n >> k;
	vector <int> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		A[i] = -A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
		B[i] = -B[i];
	}
	int L = -2e9 - 7, R = 2e9 + 7;
	int profit = 0;
	while(R - L > 1)
	{
		int midd = (R + L) / 2;
		pair <int, int> ans = solve(A, B, midd);
		if(-ans.second <= k)
		{
			L = midd;
			profit = ans.first;
		}
		else
		{
			R = midd;
		}
	}
	cout << -(profit - L * k);
	return 0;
}