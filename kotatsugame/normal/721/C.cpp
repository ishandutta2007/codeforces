#include<iostream>
using namespace std;

int main()
{
	int n, m, T;
	cin >> n >> m >> T;
	int *u = new int[m];
	int *v = new int[m];
	int *t = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> u[i] >> v[i] >> t[i];
	}

	int **dp = new int*[n + 1];
	for (int i = 0; i <= n; i++)dp[i] = new int[n + 1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = T+5;
	dp[1][1] = 0;

	int **parent = new int*[n + 1];
	for (int i = 0; i <= n; i++)parent[i] = new int[n + 1];
	int max;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dp[i-1][u[j]] + t[j] < dp[i][v[j]])
			{
				dp[i][v[j]] = dp[i-1][u[j]] + t[j];
				parent[i][v[j]] = u[j];
			}
		}
		if (dp[i][n] <= T)max = i;
	}

	int *ans = new int[max+1];
	int before = n;

	for (int i = max; i >= 1; i--)
	{
		ans[i] = before;
		before = parent[i][before];
	}
	cout << max << endl;
	for (int i = 1; i <= max; i++)
	{
		if (i != 1)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}