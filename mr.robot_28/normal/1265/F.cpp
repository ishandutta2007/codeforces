#include <bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 998244353;
int pow1(int n)
{
	int rez = 1, p = 2;
	while(n)
	{
		if(n % 2 == 1)
		{
			rez = rez * p % CONST;
		}
		p = p * p % CONST;
		n = n / 2;
	}
	return rez;
}
signed main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector <vector <int> > dp(n, vector <int> (n));
	vector <vector <int> > ans(n, vector <int> (n, 0));
	for(int len = 1; len <= n; len++)
	{
		for(int i = 0; i <= n - len; i++)
		{
			if(s[i] == '?')
			{
				if(len == 1)
				{
					ans[i][i + len - 1] = 1;
				}
				else
				{
					ans[i][i + len - 1] = ans[i + 1][i + len - 1] + 1;
				}
			}
			else
			{
				if(len == 1)
				{
					ans[i][i + len - 1] = 0;
				}
				else
				{
					ans[i][i + len - 1] = ans[i + 1][i + len - 1];
				}
			}
			if(s[i] != '(' && len >= 2 && i + len - 1 < n)
			{
				dp[i][i + len - 1] += dp[i + 1][i + len - 1];
			}
			if(s[i + len - 1] != ')' && len >= 2)
			{
				dp[i][i + len - 1] += dp[i][i + len - 2];
			}
			if(s[i] != '(' && s[i + len - 1] != ')' && len >= 2 && i + len - 1 < n)
			{
				dp[i][i + len - 1] -= dp[i + 1][i + len - 2];
			}
			if(s[i] != ')' && s[i + len - 1] != '(' && len >= 2 && i + len - 1 < n)
			{
				dp[i][i + len - 1] += dp[i + 1][i + len - 2] + pow1(ans[i + 1][i + len - 2]);
			}
			dp[i][i + len - 1] %= CONST;
		}
	}
	cout << dp[0][n - 1];
    return 0;
}