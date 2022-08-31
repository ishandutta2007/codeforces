#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL MOD = 1000000007;
LL powmod(LL a, LL b){
	if(b == 0) return 1;
	LL c = powmod(a,b/2);
	if(b%2) return (a*(c*c % MOD)) % MOD;
	return (c*c % MOD);
}
int main(){
	LL p, k;
	cin >> p >> k;
	if(k == 0){
		cout << powmod(p,p-1) << endl;
		return 0;
	} else if(k == 1){
		cout << powmod(p,p) << endl;
	} else {
		LL c = k;
		LL n = 1;
		while(c != 1){
			n++;
			c = (c*k) % p;
		}
		cout << powmod(p,p/n) << endl;
	}

}