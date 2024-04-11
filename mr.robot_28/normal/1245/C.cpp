#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
signed main(){
	string s;
	cin >> s;
	int n = s.size();
	vector <int> dp(n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == 'w' || s[i - 1] == 'm'){
			cout << 0;
			return 0;
		}
		if(i == 1){
			dp[i] = 1;
		}
		else
		{
			if(s[i - 1] == s[i - 2] && s[i - 2] == 'u')
			{
				dp[i] += dp[i - 2];
			}
			if(s[i - 1] == s[i - 2] && s[i - 2] == 'n'){
				dp[i] += dp[i - 2];
			}
			dp[i] += dp[i - 1];
			dp[i] %= CONST;
		}
	}
	cout << dp[n];
	return 0;
}