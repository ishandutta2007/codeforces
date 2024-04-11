#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint h[2005];
llint dp[2005][4005];
llint Zero = 2002;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> h[i];
	
	dp[0][Zero] = 1;
	for(int i = 0; i < n; i++){
		for(int j = -n; j <= n; j++){
			if(h[i] == h[(i+1)%n]){
				dp[i+1][Zero+j] += dp[i][Zero+j] * k % mod, dp[i+1][Zero+j] %= mod;
			}
			else{
				dp[i+1][Zero+j] += dp[i][Zero+j] * (k-2) % mod, dp[i+1][Zero+j] %= mod;
				if(j+1 <= n) dp[i+1][Zero+j+1] += dp[i][Zero+j] * 1 % mod, dp[i+1][Zero+j+1] %= mod;
				if(j-1 >= -n) dp[i+1][Zero+j-1] += dp[i][Zero+j] * 1 % mod, dp[i+1][Zero+j-1] %= mod;
			}
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = -n; j <= n; j++){
			cout << dp[i][Zero+j] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += dp[n][Zero+i], ans %= mod;
	cout << ans << endl;
	
	return 0;
}