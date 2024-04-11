#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007

using namespace std;

string s;
llint dp[100005][2];

int main(void)
{
	cin >> s;
	int n = s.size();
	s = "#" + s;
	
	for(int i = 1; i <= n; i++){
		if(s[i] == 'a'){
			dp[i][0] = dp[i-1][0] + dp[i-1][1] + 1, dp[i][0] %= mod;
			dp[i][1] = dp[i-1][1];
		}
		else if(s[i] == 'b'){
			dp[i][1] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] %= mod;
		}
		else{
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1];
		}
	}
	
	cout << (dp[n][0] + dp[n][1]) % mod << endl;
	return 0;
}