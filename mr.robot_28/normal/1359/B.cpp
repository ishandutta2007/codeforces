#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		vector <vector <char> > A(n, vector <char> (m));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> A[i][j];
			}
		}
		vector <vector <int> > dp(n, vector <int> (m, 1e9));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(A[i][j] == '*')
				{
					if(i == 0 && j == 0)
					{
						dp[i][j] = 0;
					}
					else if(j == 0){
						dp[i][j] = dp[i - 1][m - 1];
					}
					else
					{
						dp[i][j] = dp[i][j - 1];
					}
				}
				else
				{
					if(i == 0 && j == 0)
					{
						dp[i][j] = min(dp[i][j], x);
					}
					else if(j == 0)
					{
						dp[i][j] = min(dp[i][j], dp[i - 1][m - 1] + x);
					}
					else{
						dp[i][j] = min(dp[i][j], dp[i][j - 1] + x);
					}
					if(i == 0 && j == 1 && A[i][j - 1] == '.')
					{
						dp[i][j] = min(dp[i][j], y);
					}
					else if(i != 0 && j == 1 && A[i][j - 1] == '.')
					{
						dp[i][j] = min(dp[i][j], y + dp[i - 1][m - 1]);
					}
					if(j >= 2 && A[i][j - 1] == '.')
					{
						dp[i][j] = min(dp[i][j], dp[i][j - 2] + y);
					}
				}
			}
		}
		cout << dp[n - 1][m- 1] << "\n";
	}
    return 0;
}