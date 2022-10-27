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
	vector <vector <int> > dp(n, vector <int> (4, 0));
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i != 0){
			for(int j = 0; j < 4; j++)
			{
				for(int j1 = j; j1 < 4; j1++)
				{
					dp[i][j1] = max(dp[i][j1], dp[i - 1][j]);
				}
			}
		}
		for(int j = 0; j < 4; j++)
		{
			if(j % 2 == 1 - a[i] % 2)
			{
				dp[i][j]++;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans;
    return 0;
}