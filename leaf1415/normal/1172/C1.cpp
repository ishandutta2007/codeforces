#include <iostream>
#include <deque>
#include <set>
#define llint long long
#define mod 998244353

using namespace std;

llint n, m;
llint a[55], w[55];
llint dp[55][55][55];
llint inv[3005];

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
	
	for(int i = 1; i < 3005; i++){
		inv[i] = modpow(i, mod-2);
	}
	
	llint usum = 0, dsum = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) dsum += w[i], dsum %= mod, a[i] = -1;
		else usum += w[i], usum %= mod;
	}
	
	for(int p = 1; p <= n; p++){
		
		for(int i = 0; i <= m; i++){
			for(int j = 0; j <= m; j++){
				for(int k = 0; k <= m; k++){
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][0][0] = 1;
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j <= m; j++){
				for(int k = 0; k <= m; k++){
					int wp = w[p] + a[p]*j;
					int wu = usum + k, wd = dsum - (i - k);;
					if(a[p] == 1) wu -= wp;
					if(a[p] == -1) wd -= wp;
					int sum = (wp+wu+wd) % mod;
					
					int nk = k;
					if(a[p] == 1) nk++;
					dp[i+1][j+1][nk] += dp[i][j][k] * wp % mod * inv[sum] % mod;
					dp[i+1][j+1][nk] %= mod;
					dp[i+1][j][k+1] += dp[i][j][k] * wu % mod * inv[sum] % mod;
					dp[i+1][j][k+1] %= mod;
					dp[i+1][j][k] += dp[i][j][k] * wd % mod * inv[sum] % mod;
					dp[i+1][j][k] %= mod;
				}
			}
		}
		
		llint ans = 0;
		for(int j = 0; j <= m; j++){
			llint sum = 0;
			for(int k = 0; k <= m; k++){
				sum += dp[m][j][k], sum %= mod;
			}
			ans += sum * ((w[p]+a[p]*j+mod)%mod) % mod, ans %= mod;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}