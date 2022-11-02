# include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int pow(int a,int b) {
	int t = 1;
	while(b) {
		if(b&1) t = 1ll*t*a%mod;
		a = 1ll*a*a%mod;
		b = b >>1;
	}
	return t;
}

int inv(int x) { return pow(x, mod - 2); }

int f[1200][1200];
long long pa, pb, R;
int k, a, b;

int calc(int a,int b) {
	if(b >= k) return b;
	if(a + b >= k) return (a + b + R) % mod;
	if(~f[a][b]) return f[a][b];
	return f[a][b] = (pa * calc(a+1,b) + pb * calc(a, a+b)) % mod;
}

int main() {
	scanf("%d%d%d", &k, &a, &b);
	pa = 1ll * a * inv(a + b) % mod;
	pb = 1ll * b * inv(a + b) % mod;
	R = pa * pb % mod * inv(pb) % mod * inv(pb) % mod;
	memset(f, -1, sizeof(f));
	cout << calc(1, 0) << endl;
	return 0;
}