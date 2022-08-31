#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;

LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}

int main(){
	LL n, k;
	cin >> n >> k;
	vector<pair<LL,LL> > pf;
	for(LL p = 2; p * p <= n; p++){
		if(n % p == 0){
			int a = 0;
			while(n % p == 0){
				a++;
				n /= p;
			}
			pf.push_back({p, a});
		}
	}
	if(n > 1){
		pf.push_back({n, 1});
	}
	LL ans = 1;
	for(auto x : pf){
		LL p = x.first;
		LL f = x.second;
		vector<LL> dp(f+1, 0);
		dp[f] = 1;
		for(LL i = 0; i < k; i++){
			vector<LL> newdp(f+1, 0);
			for(LL b = 0; b <= f; b++){
				newdp[b] = dp[b] * inv(b+1) % MOD;
			}
			for(LL b = f; b >= 1; b--){
				newdp[b-1] += newdp[b];
				newdp[b-1] %= MOD;
			}
			dp = newdp;
		}
		LL cur = 0;
		for(LL b = 0; b <= f; b++){
			cur += dp[b] * powmod(p % MOD, b);
			cur %= MOD;
		}
		ans = (ans * cur) % MOD;
	}
	ans %= MOD;
	if(ans < 0) ans += MOD;
	cout << ans << '\n';
}