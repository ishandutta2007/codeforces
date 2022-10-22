#include <iostream>
#include <string>
#define inf 1e9

using namespace std;

int n;
string s, t;
bool del[505][505];
int dp[505][505];

int main(void)
{
	cin >> n;
	cin >> t;
	
	char c = '#';
	for(int i = 0; i < t.size(); i++){
		if(t[i] != c) s += t[i];
		c = t[i];
	}
	int n = s.size();
	s = "#" + s;
	
	for(int l = 1; l <= n; l++){
		for(int r = 1; r <= n; r++){
			if(l > r) continue;
			del[l][r] = true;
			for(int i = l; i <= r; i++){
				if(s[i] != s[l]) del[l][r] = false;
			}
		}
	}
	
	for(int len = 1; len <= n; len++){
		for(int l = 1; l+len-1 <= n; l++){
			int r = l+len-1;
			if(del[l][r]){
				dp[l][r] =1;
				continue;
			}
			dp[l][r] = inf;
			for(int i = l; i < r; i++){
				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r]);
			}
			for(int i = l+1; i <= r; i++){
				if(s[i] == s[l]){
					dp[l][r] = min(dp[l][r], dp[l+1][i-1] + dp[i][r]);
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	
	return 0;
}