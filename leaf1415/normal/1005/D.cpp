#include <iostream>
#include <string>
#include <algorithm>
#define inf 1e9

using namespace std;

string s;
int dp[200005][3][2];

int main(void)
{
	cin >> s;
	reverse(s.begin(), s.end());
	
	for(int i = 0; i <= s.size(); i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++) dp[i][j][k] = -inf;
		}
	}
	dp[0][0][1] = 0;
	
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++){
				if(i == 0 || k == 1 || s[i-1] != '0' || s[i] != '0'){
					dp[i+1][0][1] = max(dp[i+1][0][1], dp[i][j][k] + ((j+(s[i]-'0')) % 3 == 0));
				}
				dp[i+1][(j+(s[i]-'0'))%3][0] = max(dp[i+1][(j+(s[i]-'0'))%3][0], dp[i][j][k]);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 2; k++) ans = max(ans, dp[s.size()][i][k]);
	}
	cout << ans << endl;
	return 0;
}