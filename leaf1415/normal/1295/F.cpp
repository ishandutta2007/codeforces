#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18
#define mod 998244353

using namespace std;

llint n;
llint l[55], r[55];
llint L[55], R[55];
llint len[55], leninv[55], LEN[105];
llint inv[55];
vector<llint> comp;
llint dp[55][105][55];

const int FACT_MAX = 105;
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

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	make_fact();
	for(int i = 1; i < 55; i++) inv[i] = modpow(i, mod-2);
	
	cin >> n;
	for(int i = n; i >= 1; i--){
		cin >> l[i] >> r[i];
		r[i]++;
		len[i] = r[i]-l[i];
		leninv[i] = modpow(len[i], mod-2);
	}
	l[0] = -1, r[0] = 0;
	for(int i = 0; i <= n; i++){
		comp.push_back(l[i]);
		comp.push_back(r[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	llint m = (llint)comp.size()-1;
	
	for(int i = 0; i <= n; i++){
		L[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
		R[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
	}
	for(int i = 0; i < m; i++){
		LEN[i] = comp[i+1] - comp[i];
	}
	
	/*for(int i = 0; i < comp.size(); i++) cout << comp[i] << " "; cout << endl;
	for(int i = 0; i <= n; i++) cout << l[i] << " " << r[i] << endl;
	for(int i = 0; i < m; i++) cout << L[i] << " " << R[i] << endl;*/
	
	dp[0][0][1] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k <= n; k++){
				for(int q = j+1; q < m; q++){
					if(L[i+1] <= q && q < R[i+1]){
						llint pro = LEN[q] * leninv[i+1] % mod;
						//cout << LEN[q] << endl;
						//cout << i << " " << j << " " << k << " " << q << " " << pro << endl;
						dp[i+1][q][1] += dp[i][j][k] * pro % mod;
						dp[i+1][q][1] %= mod;
					}
				}
				if(L[i+1] <= j && j < R[i+1]){
					if(LEN[j]-k > 0){
						llint pro = (LEN[j]-k) * leninv[i+1] % mod * inv[k+1] % mod;
						dp[i+1][j][k+1] += dp[i][j][k] * pro % mod;
						dp[i+1][j][k+1] %= mod;
					}
					llint pro = leninv[i+1];
					dp[i+1][j][k] += dp[i][j][k] * pro % mod;
					dp[i+1][j][k] %= mod;
				}
			}
		}
	}
	
	llint ans = 0;
	for(int j = 0; j < m; j++){
		for(int k = 0; k <= n; k++){
			ans += dp[n][j][k];
			ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}