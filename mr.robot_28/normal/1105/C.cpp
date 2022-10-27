#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
signed main () {
	int n, l, r;
	cin >> n >> l >> r;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int raz1 = 0, raz2 = 0, raz3 = 0;
	if(l % 3 == 0)
	{
		raz2 = 1;
		raz3 = 2;
	}
	else if(l % 3 == 1)
	{
		raz1 = 2;
		raz3 = 1;
	}
	else
	{
		raz1 = 1;
		raz2 = 2;
	}
	if(raz1 + l <= r)
	{
		cnt1 = (r - l - raz1) / 3 + 1;
	}
	if(raz2 + l <= r)
	{
		cnt2 = (r - l - raz2) / 3 + 1;
	}
	if(raz3 + l <= r)
	{
		cnt3 = (r - l - raz3) / 3 + 1;
	}
	vector <vector <int> > dp(n, vector <int> (3, 0));
	for(int i = 0; i < n; i++){
		if(i == 0)
		{
			dp[0][0] = cnt1 % CONST;
			dp[0][1] = cnt2 % CONST;
			dp[0][2] = cnt3 % CONST;
		}
		else
		{
			for(int j = 0; j < 3; j++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j] * cnt1 % CONST) % CONST;
				dp[i][(j + 1) % 3] = (dp[i][(j + 1) % 3] + dp[i - 1][j] * cnt2 % CONST) % CONST;
				dp[i][(j + 2) % 3] = (dp[i][(j + 2) % 3] + dp[i - 1][j] * cnt3 % CONST) % CONST;
			}
		}
	}
	cout << dp[n - 1][0];
	return 0;
}