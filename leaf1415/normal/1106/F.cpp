#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#define llint long long 
#define mod 998244353

using namespace std;

llint k;
llint b[105];
llint n, m;

void add(llint x[], llint d[])
{
	static llint ret[105];
	ret[0] = x[k-1]*d[0]%(mod-1);
	for(int i = 1; i < k; i++) ret[i] = x[i-1]+x[k-1]*d[i]%(mod-1), ret[i] %= (mod-1);
	for(int i = 0; i < k; i++) x[i] = ret[i];
}

void twice(llint x[], llint d[]){
	static llint ret[105], tmp[105][105];
	for(int i = 0; i < k; i++) tmp[0][i] = x[i];
	for(int i = 1; i < k; i++){
		for(int j = 0; j < k; j++) tmp[i][j] = tmp[i-1][j];
		add(tmp[i], d);
	}
	for(int i = 0; i < k; i++) ret[i] = 0;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			ret[j] += x[i]*tmp[i][j]%(mod-1);
			ret[j] %= (mod-1);
		}
	}
	for(int i = 0; i < k; i++) x[i] = ret[i];
}

//Remark: 0-indexed
void kitamasa(llint d[], llint n)
{
	static llint ret[105];
	for(int i = 0; i < k; i++) ret[i] = 0;
	ret[0] = 1;
	for(int i = 60; i >= 0; i--){
		twice(ret, d);
		if(n & (1LL<<i)) add(ret, d);
	}
	for(int i = 0; i < k; i++) d[i] = ret[i];
}

llint gcd(llint a, llint b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

map<llint, llint> mp;
llint modlog(llint a, llint y)
{
	llint m = sqrt(mod)+1, mul = 1;
	for(int j = 0; j < m; j++){
		mp[mul] = j;
		mul = mul * a % mod;
	}
	llint g = modpow(a, m);
	g = modpow(g, mod-2);
	
	llint gamma = y;
	for(int i = 0; i < m; i++){
		if(mp.count(gamma)) return i*m+mp[gamma];
		gamma = gamma * g % mod;
	}
}

llint extgcd(llint a, llint b, llint &x, llint &y)
{
	llint d = a;
	if(b != 0){
		d = extgcd(b, a%b, y, x);
		y -= (a/b)*x;
	}else{
		x = 1, y = 0;
	}
	return d;
}

llint modinv(llint a, llint m)
{
	llint x, y;
	extgcd(a, m, x, y);
	return (m+x%m)%m;
}

int main(void)
{
	cin >> k;
	for(int i = 0; i < k; i++) cin >> b[i];
	cin >> n >> m;
	
	reverse(b, b+k);
	kitamasa(b, n-1);
	llint x = b[k-1];
	
	llint y = modlog(3, m);
	llint d = gcd(x, mod-1);
	
	//cout << (modpow(3, y) == m) << endl;
	//cout << x << " " << y << " " << m << endl;
	
	if(y%d){
		cout << -1 << endl;
		return 0;
	}
	
	llint A = x/d, B = y/d, M = (mod-1) / d;
	llint Ainv = modinv(A, M);
	
	k = B * Ainv % M;
	llint f = modpow(3, k);
	
	//cout << modpow(f, x) << " " << m << endl;
	
	if(modpow(f, x) != m) cout << -1 << endl;
	else cout << f << endl;
	
	return 0;
}