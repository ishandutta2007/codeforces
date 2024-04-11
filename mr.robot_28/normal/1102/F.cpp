# include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > A(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	if(n == 1)
	{
		int ans = 1e9;
		for(int i = 0; i < m - 1; i++)
		{
			ans = min(ans, abs(A[0][i + 1] - A[0][i]));
		}
		cout << ans;
		return 0;
	}
	vector <vector <int> > p1(n, vector <int> (n, 1e9));
	vector <vector <int> > p2(n, vector <int> (n, 1e9));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				p1[i][j] = min(p1[i][j], abs(A[i][k] - A[j][k]));
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
				for(int k = 0; k < m - 1; k++)
				{
					p2[i][j] = min(p2[i][j], abs(A[i][k] - A[j][k + 1]));
				}
		}
	}
	vector <vector <vector <int> > > dp((1 << n), vector <vector <int> > (n + 1, vector <int> (1 + n, 0)));
	for(int i = 0; i < n; i++)
	{
		dp[(1 << i)][i][i] = 1e9;
	}
	for(int i = 1; i < (1 << n); i++)
	{
		int d = i;
		vector <int> A, B;
		for(int j = 0; j < n; j++)
		{
			if((d & (1 << j)))
			{
				A.push_back(j);
			}
			else
			{
				B.push_back(j);
			}
		}
		for(int j = 0; j < A.size(); j++)
		{
			for(int t = 0; t < A.size(); t++)
			{
				for(int t1 = 0; t1 < B.size(); t1++)
				{
					if(((1 << B[t1]) | i) == (1 << n) - 1)
					{
						int k = min(p1[A[t]][B[t1]], p2[B[t1]][A[j]]);
						k = min(k, dp[i][A[j]][A[t]]);
						dp[(1 << B[t1]) | i][A[j]][B[t1]] = max(dp[(1 << B[t1]) | i][A[j]][B[t1]], k);
					}
					else
					{
						dp[(1 << B[t1]) | i][A[j]][B[t1]] = max(dp[(1 << B[t1]) | i][A[j]][B[t1]], min(p1[A[t]][B[t1]], dp[i][A[j]][A[t]]));
 					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++){
			ans = max(ans, dp[(1 << n) - 1][i][j]);
		}
	}
	cout << ans;
	return 0;
}