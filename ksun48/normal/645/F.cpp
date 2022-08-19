#include<bits/stdc++.h>
#define MOD 1000000007
#define MAXN 210000
#define MAXV 1000010
//factor numbers up to MAXV
using namespace std;
typedef long long LL;

LL n, k, q;
LL sieve[MAXV]; //smallest prime factor
vector<LL> fact[MAXV]; // list of factors
LL phi[MAXV]; // phi(x)
LL xck[MAXN]; // x choose k
LL freq[MAXV];
LL powmod(LL a, LL n){ // compute a^n mod 10^9+7
	if(n == 0) return 1;
	if(n == 1) return a;
	LL b = powmod(a, n/2);
	b = (b*b) % MOD;
	if(n%2 == 0) return b;
	return (a*b) % MOD;
}
LL ans = 0;
int main(){
	cin >> n >> k >> q;
	for(LL i = 0; i < k; i++){
		xck[i] = 0;
	}
	xck[k] = 1;
	for(LL i = k+1; i < MAXN; i++){
		xck[i] = (xck[i-1] * i) % MOD;
		xck[i] = (xck[i] * powmod(i-k,MOD-2) ) % MOD;
	}
	for(LL i = 1; i < MAXV; i++){
		sieve[i] = 1;
		phi[i] = 0;
		freq[i] = 0;
	}
	sieve[1] = 0;
	fact[1].push_back(1);
	phi[1] = 1;
	for(LL i = 2; i < MAXV; i++){
		if(sieve[i] == 1){
			fact[i].push_back(1);
			fact[i].push_back(i);
			phi[i] = i-1;
			for(LL j = 2*i; j < MAXV; j+= i){
				if(sieve[j] == 1){
					sieve[j] = i;
				}
			}
			continue;
		}
		LL p = sieve[i];
		LL r = i/p;
		if(r % p == 0){
			phi[i] = phi[r]*p;
		} else {
			phi[i] = phi[r]*(p-1);
		}
		for(LL j = 0; j < fact[r].size(); j++){
			fact[i].push_back(fact[r][j]);
			if((r/fact[r][j]) % p != 0){
				fact[i].push_back(fact[r][j]*p);
			}
		}
	}
	for(LL i = 0; i < n+q; i++){
		LL a;
		cin >> a;
		for(LL j = 0; j < fact[a].size(); j++){
			LL d = fact[a][j];
			LL r = xck[freq[d]+1]-xck[freq[d]];
			freq[d]++;
			r = (r+MOD)%MOD;
			ans = (ans + r*phi[d]) % MOD;
		}
		if(i >= n) cout << ans << endl;
	}
}