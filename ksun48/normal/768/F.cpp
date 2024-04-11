#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MOD 1000000007

LL powmod(LL a, int n){
	if(n == 0) return 1;
	if(n % 2 == 1) return (a * powmod(a,n-1)) % MOD;
	LL c = powmod(a,n/2);
	return (c*c) % MOD;
}
LL inv(LL a){
	if(a == 0) return 0;
	return powmod(a,MOD-2);
}
LL fact[110000];
LL invfact[110000];
LL ncr(LL n, LL r){
	if(r > n || r < 0) return 0;
	LL p = fact[n];
	p = (p * invfact[r]) % MOD;
	p = (p * invfact[n-r]) % MOD;
	return p;
}

int main(){
	fact[0] = invfact[0] = 1;
	for(LL i = 1; i < 110000; i++){
		fact[i] = (fact[i-1] * i) % MOD;
		invfact[i] = (invfact[i-1] * inv(i)) % MOD;
	}
	LL f, w, h;
	cin >> f >> w >> h;
	if(f == 0){
		if(w <= h){
			cout << 0 << endl;
			return 0;
		} else {
			cout << 1 << endl;
			return 0;
		}
	}
	if(w == 0){
		cout << 1 << endl;
		return 0;
	}

	LL den = 0;
	LL num = 0; // numb
	for(LL i = 1; i <= w && i <= f; i++){
		LL a = ncr(f-1,i-1) * ncr(w-1,i-1);
		a %= MOD;
		den += a;
		den %= MOD;
		den += a;
		den %= MOD;
		if((i + h*i <= w) ){
			LL b = ncr(f-1,i-1) * ncr(w-h*i-1,i-1);
			b %= MOD;
			num += b;
			num %= MOD;
			num += b;
			num %= MOD;
		}
	}
	for(LL i = 1; i <= w && (i+1 <= f); i++){
		LL a = ncr(f-1,(i+1)-1) * ncr(w-1,i-1);
		a %= MOD;
		den += a;
		den %= MOD;
		if((i + h*i <= w) ){
			LL b = ncr(f-1,(i+1)-1) * ncr(w-h*i-1,i-1);
			b %= MOD;
			num += b;
			num %= MOD;
		}		
	}
	for(LL i = 1; (i+1 <= w) && i <= f; i++){
		LL a = ncr(w-1,(i+1)-1) * ncr(f-1,i-1);
		a %= MOD;
		den += a;
		den %= MOD;
		if( ((i+1) + h*(i+1) <= w) ){
			LL b = ncr(w-h*(i+1)-1,(i+1)-1) * ncr(f-1,i-1);
			b %= MOD;
			num += b;
			num %= MOD;
		}		
	}
	num *= inv(den);
	num %= MOD;
	while(num < 0) num += MOD;
	num %= MOD;
	cout << num  << endl;
}