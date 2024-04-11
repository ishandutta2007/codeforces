#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 998244353

using namespace std;

llint n, K;
llint dp[1005][1005][2], sum[2][1005];
llint a[1005], ub[100005], lb[100005];
bool used[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> K;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	for(int i = 1; i <= n; i++) used[a[i]] = true;
	for(int i = 0; i < 100005; i++){
		if(!used[i]){
			ub[i] = lb[i] = ub[i-1];
			if(i == 0) ub[i] = lb[i] = 0;
			continue;
		}
		ub[i] = upper_bound(a+1, a+n+1, i) - a - 1;
		lb[i] = lower_bound(a+1, a+n+1, i) - a - 1;
	}
	
	llint m = 100000 / (K-1), ans = 0;
	for(int d = 1; d <= m; d++){
		
		for(int i = 1; i <= K; i++){
			for(int j = 0; j <= n; j++){
				for(int k = 0; k < 2; k++){
					dp[i][j][k] = 0;
				}
			}
		}
		for(int j = 1; j <= n; j++) dp[1][j][0] = 1;
		
		for(int i = 2; i <= K; i++){
			for(int j = 1; j <= n; j++){
				sum[0][j] = (sum[0][j-1] + dp[i-1][j][0]) % mod;
				sum[1][j] = (sum[1][j-1] + dp[i-1][j][1]) % mod;
			}
			for(int j = 1; j <= n; j++){
				llint just = a[j]-d;
				if(just >= 0) dp[i][j][0] += sum[0][lb[just]], dp[i][j][0] %= mod;
				
				if(just >= 0){
					dp[i][j][1] += sum[1][ub[just]], dp[i][j][1] %= mod;
					dp[i][j][1] += sum[0][ub[just]] - sum[0][lb[just]] + mod, dp[i][j][1] %= mod;
				}
			}
		}
		for(int j = 1; j <= n; j++) ans += d * dp[K][j][1] % mod, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}