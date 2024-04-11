#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
string s;
llint dp[200005][3][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> s;
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'L') s[i] = '0';
			else s[i] = '1';
		}
		
		llint ans = inf;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				
				for(int k = 0; k <= n+2; k++){
					for(int l = 0; l < 3; l++){
						for(int m = 0; m < 2; m++){
							dp[k][l][m] = inf;
						}
					}
				}
				dp[0][0][0] = 0;
				
				for(int k = 0; k < n+2; k++){
					for(int l = 0; l < 3; l++){
						for(int m = 0; m < 2; m++){
							for(int x = 0; x < 2; x++){
								if(k == 0 && i != x) continue;
								if(k == 1 && j != x) continue;
								if(k == n && i != x) continue;
								if(k == n+1 && j != x) continue;
								llint cost = 0;
								if(k < n && s[k]-'0' != x) cost = 1;
								if(m == x){
									if(l+1 < 3) chmin(dp[k+1][l+1][x], dp[k][l][m] + cost);
								}else chmin(dp[k+1][1][x], dp[k][l][m] + cost);
							}
						}
					}
				}
				
				for(int l = 0; l < 3; l++){
					for(int m = 0; m < 2; m++){
						ans = min(ans, dp[n+2][l][m]);
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}