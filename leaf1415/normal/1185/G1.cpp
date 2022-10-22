#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define llint long long
#define mod 1000000007
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, T;
llint t[15], g[15];
llint dp[1<<15][250][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> T;
	for(int i = 0; i < n; i++) cin >> t[i] >> g[i], g[i]--;
	
	int S = 1<<n;
	llint ans = 0;
	dp[0][0][0] = 1;
	for(int j = 0; j < S; j++){
		for(int k = 0; k <= T; k++){
			for(int l = 0; l < 3; l++){
				for(int m = 0; m < n; m++){
					if(j & (1<<m)) continue;
					if(j != 0 && g[m] == l) continue;
					if(k+t[m] <= T) (dp[j | (1<<m)][k+t[m]][g[m]] += dp[j][k][l]) %= mod;
				}
			}
		}
	}
	/*for(int j = 0; j < S; j++){
		for(int k = 0; k <= T; k++){
			for(int l = 0; l < 3; l++){
				cout << dp[j][k][l] << " ";
			}
			cout << endl;
		}cout << endl;
	}*/
	for(int l = 0; l < 3; l++){
		for(int j = 0; j < S; j++){
			ans += dp[j][T][l], ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}