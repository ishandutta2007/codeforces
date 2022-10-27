#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	vector <vector <char> > A(n, vector <char> (n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	vector <vector <vector <vector <int> > > > dp(n, vector <vector <vector <int> > > (n, vector <vector <int> > (n + 1, vector <int> (n + 1))));
	for(int a = 1; a <= n; a++)
	{
		for(int b = 1; b <= n; b++)
		{
			for(int i = 0; i <= n - a; i++)
			{
				for(int j = 0; j <= n - b; j++)
				{
					if(a == 1 && b == 1 && A[i][j] == '.')
					{
						dp[i][j][a][b] = 0;
					}
					else
					{
						dp[i][j][a][b] = max(a, b);
						for(int k = i + 1; k < a + i; k++)
						{
							dp[i][j][a][b] = min(dp[i][j][a][b], dp[i][j][k - i][b] + dp[k][j][a + i - k][b]);
						}
						for(int k = j + 1; k < j + b; k++)
						{
							dp[i][j][a][b] = min(dp[i][j][a][b], dp[i][j][a][k - j] + dp[i][k][a][j + b - k]);
						}
					}
				}
			}
		}
	}
	cout << dp[0][0][n][n];
	return 0;
}