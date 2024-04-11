#include<bits/stdc++.h>
using namespace std;

signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	a.push_back(1);
	vector <int> b;
	int c = -1;
	for(int i = 0; i < a.size(); i++)
	{
		int j = i;
		while(j < a.size() && a[j] == 0)
		{
			j++;
		}
		b.push_back(j - i);
		i = j;
	}
	for(int i = 1; i < b.size(); i++)
	{
		b[i] += b[i - 1];
	}
	c = b.back();
	vector <vector <vector <int> > > dp(b.size() + 1, vector <vector <int> > (n + 1, vector <int> (n * (n + 1) / 2 + 1, 1e9)));
	dp[0][0][0] = 0;
	for(int i = 1; i <= b.size(); i++)
	{
		for(int j = 0; j <=c; j++)
		{ 
			for(int j1 = 0; j1 + j <= c; j1++)
			{
				for(int k = 0; k  <= n * (n - 1) / 2; k++)
				{
					dp[i][j + j1][k + abs(b[i - 1] - (j + j1))] = min(dp[i - 1][j][k] + j1 * j1, dp[i][j + j1][k + abs(b[i - 1] - (j + j1))]);
				}
			}
		}
	}
	int minval = 1e9;
	for(int s = 0; s <= n * (n - 1) / 2; s++)
	{
		minval = min(minval, dp[b.size()][c][s]);
		cout << ((c) * (c) - minval) / 2 << " ";
	}
    return 0;
}