#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> p(2 * n);
		for(int i = 0; i < n * 2; i++)
		{
			cin >> p[i];
		}
		vector <vector <bool> > dp(2 * n + 1, vector <bool> (n + 1, 0));
		dp[0][0] = 1;
		for(int i = 0; i < 2 * n; i++)
		{
			int j = i;
			while(j < n * 2 - 1 && p[j + 1] < p[i])
			{
				j++;
			}
			for(int k = 0; k <= n; k++)
			{
				if(!dp[i][k])
				{
					continue;
				}
				dp[j + 1][k] = true;
				if(k + (j - i + 1) <= n)
				{
					dp[j + 1][k + (j - i + 1)] = true;
				}
			}
		}
		if(dp[n * 2][n])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
  	return 0;
}