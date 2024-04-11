#include<iostream>
#include<vector>
using namespace std;
int main()
{
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
	vector <vector <int> > dp(n, vector <int> (m, 0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(dp[i][j] == 0)
			{
				bool flag = true;
				int u = i + 1;
				while(u < n && A[u][j] == A[i][j])
				{
					u++;
				}
				u--;
				int l = u + 1 - i;
				if(u + 2 * l >= n)
				{
					dp[i][j] = -1;
					continue;
				}
				for(int k = u + 1; k <= u + l; k++)
				{
					if(A[u + 1][j] != A[k][j] || A[u + 1][j] == A[i][j])
					{
						flag = false;
						break;
					}
				}
				for(int k = u + l + 1; k <= u + 2 * l; k++)
				{
					if(A[u + 1 + l][j] != A[k][j] || A[k][j] == A[u + 1][j])
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					dp[i][j] = l;
					for(int k = i + 1; k <= u; k++)
					{
						dp[k][j] = -1;
					}
				}
				else
				{
					dp[i][j] = -1;
				}
			}
		}
	}
	int rez = 0;
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		for(int j = 0; j < m; j++)
		{
			if(j == 0)
			{
				if(dp[i][j] != -1)
				{
					cnt = 1;
				}
			}
			else if(A[i][j] == A[i][j - 1] && dp[i][j] == dp[i][j - 1] && dp[i][j] > 0)
			{
				int l = dp[i][j];
				if(A[i + l][j] == A[i + l][j - 1] && A[i + 2 * l][j] == A[i + 2 * l][j - 1])
				{
					cnt++;
				}
				else
				{
					rez += (cnt + 1) * cnt / 2;
					cnt = 1;
				}
			}
			else
			{
				rez += (cnt + 1) * cnt / 2;
				if(dp[i][j] != -1)
				{
					cnt = 1;
				}
				else
				{
					cnt = 0;
				}
			}
		}
		rez += cnt * (cnt + 1) / 2;
	}
	cout << rez;
	return 0;
}