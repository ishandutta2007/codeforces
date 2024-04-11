#include<bits/stdc++.h>
#define MOD 4294967296
using namespace std;
typedef unsigned long long LL;
LL powmod(LL a, LL n){
	if(n == 0) return a;
	LL c = powmod(a,n/2);
	c = (c*c) % MOD;
	if(n % 2 == 0) return c;
	return (c*a)%MOD;
}
LL inv(LL a){
	return powmod(a,MOD/2-1) % MOD;
}
int main(){
	LL n, p, q;
	cin >> n >> p >> q;
	if(p >= n-1){
		p = n-1;
	}
	LL stuff[p+1];
	stuff[0] = 1;
	for(LL i = 0; i <= p; i++){
		LL num = 1;
		LL den = 1;
		LL f2 = 0;
		for(LL c = 1; c <= i; c++){
			LL d = c;
			while(d % 2 == 0){
				d /= 2;
				f2++;
			}
			den = (den*d) % MOD;
		}
		for(LL c = 1; c <= i; c++){
			LL d = n-c+1;
			while(f2 > 0 && d % 2 == 0){
				f2--;
				d /= 2;
			}
			num = (num*d) % MOD;
		}
		num *= inv(den);
		num %= MOD;
		stuff[i] = num;
		stuff[i] %= MOD;
	}
	LL ans = 0;
	for(LL c = 1; c <= q; c++){
		LL sum = 0;
		LL cur = 1;
		for(LL i = 0; i <= p; i++){
			cur *= c;
			cur %= MOD;
			sum += cur*stuff[i];
			sum %= MOD;
		}
		sum %= MOD;
		ans ^= sum;
	}
	cout << ans << endl;
}