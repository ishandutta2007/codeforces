#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1  =1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector <int> dp(2e6 + 1);
	dp[1] = 0;
	dp[2] = 0;
	vector <int> r(2e6 + 1, 0);
	for(int i = 3; i <= 2e6; i++)
	{
		dp[i] = 2 * dp[i - 2]+ dp[i - 1];
		if(r[i - 2] == 0 && r[i - 1] == 0)
		{
			r[i] = 1;
			dp[i] = dp[i - 2] * 2 + dp[i - 1] + 4;
		}
		dp[i] = dp[i] % const1;
	}
	while(t--){
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}