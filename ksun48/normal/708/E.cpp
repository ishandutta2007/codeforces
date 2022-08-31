#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n % 2) return (a*powmod(a,n-1)) % MOD;
	LL c = powmod(a,n/2);
	return (c*c) % MOD;
}
LL inv(LL a){
	return powmod(a,MOD-2);
}

LL fact[211000];
LL invfact[211000];

LL nck(LL n, LL k){
	if(k > n || k < 0) return 0;
	LL a = (fact[n]*invfact[k]) % MOD;
	a *= invfact[n-k];
	a %= MOD;
	return a;
}

LL prob[2000];
LL prob2[2000]; // <=

int n, m; 
LL a, b;
LL p;
LL q;

int k;

LL dp1[2000][2000];
LL dp2[2000][2000];


int main(){
	cin >> n >> m >> a >> b >> k;
	fact[0] = 1;
	fact[0] = 1;
	for(LL i = 1; i <= 210000; i++) fact[i] = (fact[i-1]*i) % MOD;
	invfact[210000] = inv(fact[210000]);
	for(LL i = 210000-1; i >= 0; i--) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
	p = (a*inv(b)) % MOD;
	q = (MOD+1-p) % MOD;

	for(int i = 0; i <= m; i++){
		prob[i] = nck(k,i);
		if(i <= k){
			prob[i] *= powmod(q,k-i);
			prob[i] %= MOD;
			prob[i] *= powmod(p,i);
			prob[i] %= MOD;
		}
		prob2[i] = 0;
		if(i > 0) prob2[i] = prob2[i-1];
		prob2[i] = (prob2[i] + prob[i]) % MOD;
	}
	for(int i = 0; i < 2000; i++){
		for(int j = 0; j < 2000; j++){
			dp1[i][j] = dp2[i][j] = 0;
		}
	}
	for(int j = 0; j < m; j++){
		dp2[0][j] = prob[j];
	}
	for(int i = 1; i <= n; i++){
		// 1 -> 1
		LL cur = 0;
		for(int j = m-1; j > 0; j--){
			cur += dp1[i-1][j]*prob2[m-j-1];
			cur %= MOD;
			dp1[i][j-1] += cur*prob[j-1];
			dp1[i][j-1] %= MOD;
		}
		// 1 -> 2
		cur = 0;
		for(int j = m-1; j > 0; j--){
			cur += dp1[i-1][j]*prob2[m-j-1];
			cur %= MOD;
			LL d = cur * prob[j-1];
			d %= MOD;
			d *= prob2[j-1];
			dp2[i][j-1] += d;
			dp2[i][j-1] %= MOD;
		}
		cur = 0;
		for(int j = 1; j < m; j++){
			cur += dp1[i-1][j]*prob2[j-1];
			cur %= MOD;
			LL d = cur * prob2[m-1-j];
			d %= MOD;
			d *= prob[j];
			d %= MOD;
			dp2[i][j] += d;
			dp2[i][j] %= MOD;
		}
		//2->1
		for(int j = 0; j < m; j++){
			LL d = dp2[i-1][j] * prob2[m-1-j];
			d %= MOD;
			dp1[i][j] += d;
			dp1[i][j] %= MOD;
		}
		//2 -> 2
		cur = 0;
		for(int j = 0; j < m; j++){
			cur += dp2[i-1][j];
			cur %= MOD;
			LL d = cur * prob[j];
			d %= MOD;
			d *= prob2[m-1-j];
			d %= MOD;

			dp2[i][j] += d;
			dp2[i][j] %= MOD;
		}
	}

	LL ans = 0;
	for(int j = 1; j < m; j++){
		LL d = dp1[n][j];
		ans += d;
		ans %= MOD;
	}
	ans += dp2[n][0]*inv(prob[0]);
	ans %= MOD;
	cout << ans << endl;

}