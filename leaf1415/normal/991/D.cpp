#include <iostream>
#include <string>
#define inf 1000000000

using namespace std;

string s[2];
int map[105][2];
int dp[105][4];

int main(void)
{
	cin >> s[0] >> s[1];
	int n = s[0].size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			if(s[j][i] == '0') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	
	for(int i = 0; i <= s[0].size(); i++){
		for(int j = 0; j < 4; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][map[0][0] | (map[0][1]*2)] = 0;
	
	for(int i = 0; i < s[0].size(); i++){
		for(int j = 0; j < 4; j++){
			if(i < s[0].size()-1){
				if(j == 0){
					if(map[i+1][0] == 0) dp[i+1][1 | (map[i+1][1]*2)] = max(dp[i+1][1 | (map[i+1][1]*2)], dp[i][j] + 1);
					if(map[i+1][1] == 0) dp[i+1][2 | map[i+1][0]] = max(dp[i+1][2 | map[i+1][0]], dp[i][j] + 1);
				}
				if((j&1) == 0){
					if(map[i+1][0] == 0 && map[i+1][1] == 0) dp[i+1][3] = max(dp[i+1][3], dp[i][j] + 1);
				}
				if((j&2) == 0){
					if(map[i+1][0] == 0 && map[i+1][1] == 0) dp[i+1][3] = max(dp[i+1][3], dp[i][j] + 1);
				}
			}
			dp[i+1][map[i+1][0] | (map[i+1][1]*2)] = max(dp[i+1][map[i+1][0] | (map[i+1][1]*2)], dp[i][j]);
		}
	}
	
	/*for(int i = 0; i < s[0].size(); i++){
		for(int j = 0; j < 4; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	int ans = 0;
	for(int i = 0; i < 4; i++) ans = max(ans, dp[s[0].size()][i]);
	cout << ans << endl;
	return 0;
}