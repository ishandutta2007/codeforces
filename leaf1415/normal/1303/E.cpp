#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1000

using namespace std;

llint Q;
string s, t;
short dp[405][405][405];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> s >> t;
		llint S = s.size(), T = t.size();
		s = "#" + s, t = "#" + t;
		
		for(int i = 0; i <= S; i++){
			for(int j = 0; j <= T; j++){
				for(int k = 0; k <= T; k++){
					dp[i][j][k] = inf;
				}
			}
		}
		for(int i = 0; i <= T; i++) dp[0][0][i] = i;
		
		for(int i = 0; i < S; i++){
			for(int j = 0; j <= T; j++){
				for(int k = 0; k <= T; k++){
					if(s[i+1] == t[j+1] && j+1 <= T){
						dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);
					}
					if(s[i+1] == t[k+1] && k+1 <= T){
						dp[i+1][j][k+1] = min(dp[i+1][j][k+1], dp[i][j][k]);
					}
					dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
				}
			}
			
		}
		
		for(int i = 0; i <= S; i++){
			for(int j = 0; j <= T; j++){
				if(dp[i][j][T] <= j){
					cout << "YES" << endl;
					goto end;
				}
			}
		}
		cout << "NO" << endl;
		end:;
	}
	flush(cout);
	
	return 0;
}