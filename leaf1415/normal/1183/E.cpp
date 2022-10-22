#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define llint long long
#define lim 1e13

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
string s;
llint nx[105][26];
llint dp[105][105];
llint num[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s;
	s = "#" + s;
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 26; j++){
			nx[i][j] = n+1;
			for(int k = i+1; k <= n; k++){
				if(s[k] == 'a'+j){
					nx[i][j] = k;
					break;
				}
			}
		}
	}
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k < 26; k++){
				if(nx[i][k] == n+1) continue;
				dp[nx[i][k]][j+1] += dp[i][j];
				if(dp[nx[i][k]][j+1] >= lim) dp[nx[i][k]][j+1] = lim;
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			num[i] += dp[j][i];
			if(num[i] > lim) num[i] = lim;
		}
	}
	
	llint ans = 0, rem = k;
	for(int i = n; i >= 0; i--){
		if(num[i] >= rem){
			ans += (n-i) * rem;
			rem = 0;
			break;
		}
		else{
			ans += (n-i) * num[i];
			rem -= num[i];
		}
	}
	if(rem > 0) ans = -1;
	cout << ans << endl;
	
	return 0;
}