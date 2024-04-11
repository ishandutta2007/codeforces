#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint k, a, b;
llint dp[1005][1005];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k >> a >> b;
	
	llint pa = a * modpow(a+b, mod-2) % mod;
	llint pb = b * modpow(a+b, mod-2) % mod;
	llint ipb = modpow(pb, mod-2);
	
	dp[1][0] = 1;
	
	llint ans = 0;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < k; j++){
			if(i+j < k){
				dp[i+1][j] += dp[i][j] * pa % mod, dp[i+1][j] %= mod;
				dp[i][j+i] += dp[i][j] * pb % mod, dp[i][j+i] %= mod;
			}
			else{
				llint tmp = (i+j-1 + ipb) % mod;
				tmp *= dp[i][j], tmp %= mod;
				ans += tmp, ans %= mod;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}