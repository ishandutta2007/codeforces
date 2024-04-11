#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<short, short> P;

string s, t;
short dp[205][205][205];
pair<P, short> rec[205][205][205];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	llint S = s.size(), T = t.size();
	s = "#" + s, t = "#" + t;
	
	for(int i = 0; i <= S; i++){
		for(int j = 0; j <= T; j++){
			for(int k = 0; k <= 200; k++){
				dp[i][j][k] = 10000;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int i = 0; i <= S; i++){
		for(int j = 0; j <= T; j++){
			if( (i+1 <= S && s[i+1] == ')') || (j+1<=T && t[j+1] == ')') ){
				for(int k = 0; k <= 200; k++){
					int ni = i, nj = j;
					if(i+1 <= S && s[i+1] == '(') ni++;
					if(j+1 <= T && t[j+1] == '(') nj++;
					if(k+1 <= 200){
						if(dp[ni][nj][k+1] > dp[i][j][k] + 1){
							dp[ni][nj][k+1] = dp[i][j][k] + 1;
							rec[ni][nj][k+1] = make_pair(P(i, j), k);
						}
					}
					ni = i, nj = j;
					if(i+1 <= S && s[i+1] == ')') ni++;
					if(j+1 <= T && t[j+1] == ')') nj++;
					if(k-1 >= 0){
						if(dp[ni][nj][k-1] > dp[i][j][k] + 1){
							dp[ni][nj][k-1] = dp[i][j][k] + 1;
							rec[ni][nj][k-1] = make_pair(P(i, j), k);
						}
					}
				}
			}
			else{
				for(int k = 200; k >= 0; k--){
					int ni = i, nj = j;
					if(i+1 <= S && s[i+1] == '(') ni++;
					if(j+1 <= T && t[j+1] == '(') nj++;
					if(k+1 <= 200){
						if(dp[ni][nj][k+1] > dp[i][j][k] + 1){
							dp[ni][nj][k+1] = dp[i][j][k] + 1;
							rec[ni][nj][k+1] = make_pair(P(i, j), k);
						}
					}
					ni = i, nj = j;
					if(i+1 <= S && s[i+1] == ')') ni++;
					if(j+1 <= T && t[j+1] == ')') nj++;
					if(k-1 >= 0){
						if(dp[ni][nj][k-1] > dp[i][j][k] + 1){
							dp[ni][nj][k-1] = dp[i][j][k] + 1;
							rec[ni][nj][k-1] = make_pair(P(i, j), k);
						}
					}
				}
			}
		}
	}
	
	string ans;
	int i = S, j = T, k = 0;
	while(i != 0 || j != 0 || k != 0){
		if(rec[i][j][k].second < k) ans += "(";
		else ans += ")";
		int ni = rec[i][j][k].first.first, nj = rec[i][j][k].first.second, nk = rec[i][j][k].second;
		i = ni, j = nj, k = nk;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	
	return 0;
}