#include <iostream>
#include <deque>
#include <set>
#define llint long long
#define mod 998244353

using namespace std;

llint n, m;
llint a[200005], w[200005];
llint dp[3005][3005];
llint dp2[3005][3005], dp3[3005][3005];
llint uexp, dexp;
llint inv[6005], inv2[6005], inv3[6005];

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

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
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> w[i];
	
	llint usum = 0, dsum = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) dsum += w[i], dsum %= mod, a[i] = -1;
		else usum += w[i], usum %= mod;
	}
	
	const int Zero = 3002; llint osum = usum + dsum;
	for(int i = -3002; i <= 3002; i++){
		llint x = osum + i;
		if(x <= 0) continue;
		inv[i+Zero] = modpow(x, mod-2);
	}
	for(int i = -3002; i <= 3002; i++){
		llint x = usum + i;
		if(x <= 0) continue;
		inv2[i+Zero] = modpow(x, mod-2);
	}
	for(int i = -3002; i <= 3002; i++){
		llint x = dsum + i;
		if(x <= 0) continue;
		inv3[i+Zero] = modpow(x, mod-2);
	}
	
	dp[0][0] = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= i; j++){
			llint wd = dsum - (i-j), wu = usum + j, sum = (wd + wu) % mod;
			if(wd < 0 || wu < 0) continue;
			dp[i+1][j] += dp[i][j] * wd % mod * inv[sum-osum+Zero] % mod, dp[i+1][j] %= mod;
			if(j+1 <= m) dp[i+1][j+1] += dp[i][j] * wu % mod * inv[sum-osum+Zero] % mod, dp[i+1][j+1] %= mod;
		}
	}
	
	dp2[0][0] = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= i; j++){
			llint wp = j+1, wu = (usum-1) + (i-j), sum = (wp + wu) % mod;
			if(wp < 0 || wu < 0) continue;
			dp2[i+1][j] += dp2[i][j] * wu % mod * inv2[sum-usum+Zero] % mod, dp2[i+1][j] %= mod;
			if(j+1 <= m) dp2[i+1][j+1] += dp2[i][j] * wp % mod * inv2[sum-usum+Zero] % mod, dp2[i+1][j+1] %= mod;
		}
	}
	dp3[0][0] = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= min(i, 1); j++){
			llint wp = 1-j, wd = (dsum-1) - (i-j), sum = (wp + wd) % mod;
			if(wp < 0 || wd < 0) continue;
			dp3[i+1][j] += dp3[i][j] * wd % mod * inv3[sum-dsum+Zero] % mod, dp3[i+1][j] %= mod;
			if(j+1 <= m) dp3[i+1][j+1] += dp3[i][j] * wp % mod * inv3[sum-dsum+Zero] % mod, dp3[i+1][j+1] %= mod;
		}
	}
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= m; j++){
			uexp += dp[m][i] * dp2[i][j] % mod * (j+1) % mod, uexp %= mod;
		}
	}
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= 1; j++){
			dexp += dp[m][m-i] * dp3[i][j] % mod * (1-j) % mod, dexp %= mod;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i] == 1) cout << w[i] * uexp % mod  << "\n";
		else cout << w[i] * dexp % mod << "\n";
	}
	flush(cout);
	
	return 0;
}