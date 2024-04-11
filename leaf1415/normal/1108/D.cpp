#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;
int dp[200005][3];
int pre[200005][3];
char c[] = {'R', 'G', 'B'};

int main(void)
{
	cin >> n;
	cin >> s;
	s = "#" + s;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++) dp[i][j] = 1e9;
	}
	for(int i = 0; i < 3; i++){
		if(s[1] != c[i]) dp[1][i] = 1;
		else dp[1][i] = 0;
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(j == k) continue;
				int cost = 0;
				if(c[k] != s[i+1]) cost = 1;
				if(dp[i+1][k] > dp[i][j] + cost){
					dp[i+1][k] = dp[i][j] + cost;
					pre[i+1][k] = j;
				}
			}
		}
	}
	
	int ans = 1e9, cur;
	for(int i = 0; i < 3; i++){
		if(ans > dp[n][i]){
			ans = dp[n][i];
			cur = i;
		}
	}
	cout << ans << endl;
	
	string ans_s;
	for(int i = n; i >= 1; i--){
		ans_s += c[cur];
		cur = pre[i][cur];
	}
	reverse(ans_s.begin(), ans_s.end());
	cout << ans_s << endl;
	
	return 0;
}