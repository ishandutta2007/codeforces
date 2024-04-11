#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n % 2 == 1) return (a * powmod(a, n-1)) % MOD;
	LL c = powmod(a, n/2);
	return (c*c) % MOD;
}
int main(){
	LL n, m;
	cin >> n >> m;
	LL a = powmod(n+1, m-1);
	LL b = powmod(2, m);
	a = (a*b) % MOD;
	a = (a*(n+1-m)) % MOD;
	cout << a << endl;
	// (2(n+1))^m * (n+1-m)/(n+1)
}