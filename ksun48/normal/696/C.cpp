#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MOD 1000000007
LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n % 2) return (a*powmod(a,n-1)) % MOD;
	LL c = powmod(a, n/2);
	return (c*c) % MOD;
}
LL inv(LL a){
	return powmod(a,MOD-2);
}
int main(){
	LL k;
	scanf("%I64d", &k);
	LL c[k];
	int odd = 1;
	LL d = 2;
	for(int i = 0; i < k; i++){
		scanf("%I64d", &c[i]);
		if(c[i] % 2 == 0) odd = 0;
		d = powmod(d,c[i]);
	}
	if(odd){
		LL p = d*inv(6)-inv(3);
		p = (p % MOD) + MOD;
		p %= MOD;
		LL q = (d*inv(2)) % MOD;
		cout << p << "/" << q << endl;
	} else {
		LL p = d*inv(6)+inv(3);
		p = (p % MOD) + MOD;
		p %= MOD;
		LL q = (d*inv(2)) % MOD;
		cout << p << "/" << q << endl;
	}

}