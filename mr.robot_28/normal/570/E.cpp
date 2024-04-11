#include <bits/stdc++.h>
 
using namespace std;
const int cnst = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <char> > A(n, vector <char> (m));
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m; j++)
    	{
    		cin >> A[i][j];
		}
	}
	vector <vector <vector <int> > > dp(2, vector <vector <int> > (m, vector <int> (n, 0)));
	if(A[0][0] != A[n - 1][m - 1])
	{
		cout << 0;
		return 0;
	}
	dp[0][0][n - 1] = 1;
	int ans = 0;
	for(int x1 = 0; x1 < n; x1++)
	{
		for(int y1 = 0; y1 < m; y1++)
		{
			for(int x2 = 0; x2 < n; x2++)
			{
				dp[(x1 + 1) % 2][y1][x2] = 0;
			}
		}
		for(int y1 = 0; y1 < m; y1++)
		{
			for(int x2 = n - 1; x2 >= 0; x2--)
			{
				int y2 = n + m  - 2- x1 - y1 - x2;
				if(y2 >= 0 && dp[x1 % 2][y1][x2] != 0)
				{
					if(x1 == x2 && y1 == y2)
					{
					ans = (ans + dp[x1 % 2][y1][x2]) % cnst;
					}
					if(x1 < n - 1 && y1 == y2 && x2 == x1 + 1)
					{
						ans = (ans + dp[x1 % 2][y1][x2]) % cnst;
					}
					if(y1 < m - 1 && x1 == x2 && y2 == y1 + 1)
					{
						ans = (ans + dp[x1 % 2][y1][x2]) % cnst;
					}
					if(x1 < n - 1 && x2 > 0 && A[x1 + 1][y1] == A[x2  - 1][y2])
					{
						dp[(x1 + 1) % 2][y1][x2 - 1] = (dp[(x1 + 1) % 2][y1][x2 - 1] + dp[x1 % 2][y1][x2]) % cnst;
					}
					if(x1 < n - 1 && y2 > 0 && A[x1 + 1][y1] == A[x2][y2 - 1])
					{
						dp[(x1 + 1) % 2][y1][x2] = (dp[(x1 + 1) % 2][y1][x2] + dp[x1 % 2][y1][x2]) % cnst;
					}
					if(y1 < m - 1 && x2 > 0 && A[x1][y1 + 1] == A[x2 - 1][y2])
					{
						dp[x1 % 2][y1 + 1][x2 - 1] = (dp[x1 % 2][y1 + 1][x2 - 1] + dp[x1 % 2][y1][x2]) % cnst;
					}
					if(y1 < m - 1 && y2 > 0 && A[x1][y1 + 1] == A[x2][y2 - 1])
					{
						dp[x1 % 2][y1 + 1][x2] = (dp[x1 % 2][y1 + 1][x2] + dp[x1 % 2][y1][x2]) % cnst;
					}
				}
			}
		}
	}
	cout << ans;
    return 0;
}