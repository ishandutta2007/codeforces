#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
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
	LL n;
	cin >> n;
	map<int,int> deg;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		deg[a]++;
		deg[b]++;
	}
	LL nl = 0;
	for(int i = 0; i < n; i++){
		if(deg[i] == 1) nl++;
	}
	LL ans = (n-nl)*powmod(2, n-nl) + nl*powmod(2, n-nl+1);
	ans %= MOD;
	cout << ans << endl;
}