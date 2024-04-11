#include<bits/stdc++.h>
 
using namespace std;
#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, g, b;
	cin >> r >> g >> b;
	vector <int> R(r), G(g), B(b);
	for(int i = 0; i < r; i++)
	{
		cin >> R[i];
	 } 
	for(int i = 0; i < g; i++)
	{
		cin >> G[i];
	}
	for(int i = 0; i < b; i++)
	{
		cin >> B[i];
	}
	sort(R.begin(), R.end());
	sort(G.begin(), G.end());
	sort(B.begin(), B.end());
	int ans = 0;
	vector <vector <vector <int> > > dp(r + 1, vector <vector <int> > (g + 1, vector <int> (b + 1, -1e18)));
	dp[0][0][0] = 0;
	for(int i = 0; i <= r; i++)
	{
		for(int j = 0; j <= g; j++)
		{
			for(int k = 0; k <= b; k++)
			{
				if(i + 1 <= r && j + 1 <= g)
				{
					dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + R[r - 1 - i] * G[g - 1 - j]);
				}
				if(i + 1 <= r && k + 1 <= b)
				{
					dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + R[r - 1 - i] * B[b - 1 - k]);
				}
				if(j + 1 <= g && k + 1 <= b)
				{
					dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + G[g - 1 - j] * B[b - 1 - k]);
				}
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans;
	return 0;
}