#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
  return (a ==0)?b:gcd(b%a,a);
}
LL phip(LL prime, LL k){
	LL a = prime-1;
	for(int i = 1; i < k; i++) a *= prime;
	return a;
}
LL phi(LL a){
	if(a == 1) return 1;
	for(int i = 2; i*i <= a; i++){
		if(a % i == 0){
			int r =0;
			while(a % i == 0){
				r++;
				a /= i;
			}
			return phip(i,r)*phi(a);
		}
	}
	return phip(a,1);
}
LL p;
vector<LL> div;
LL powmod(LL a, LL pow){
	if(pow == 0) return 1;
	LL k = powmod(a, pow/2);
	if(pow % 2) return (((k*k)%p)*a)% p;
	return (k*k) % p;
}
LL ord(LL a){
	LL orda = p-1;
	for(int i = 0; i < div.size(); i++){
		if(powmod(a,div[i]) == 1){
			orda = min(orda, div[i]);
		}
	}
	return orda;
}
int main(){

	LL n, m;
	cin >> n >> m >> p;
	LL i;
	for(i = 1; i*i <= p-1; i++){
		if((p-1)% i == 0){
			div.push_back(i);
			div.push_back((p-1)/i);
		}
	}
	LL a[n];
	LL b[m];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	LL g = p-1;
	for(int i = 0; i < m; i++){
		g = gcd(g, b[i]);
	}
	LL ordag[n];
	for(int i = 0; i < n; i++){
		ordag[i] = ord(a[i])/gcd(ord(a[i]), g);
	}
	LL ans = 0;
	for(int i = 0; i < div.size(); i++){
		for(int j = 0; j < n; j++){
			if(ordag[j] % div[i] == 0){
				ans += phi(div[i]);
				break;
			}
		}
	}
	cout << ans << endl;
}