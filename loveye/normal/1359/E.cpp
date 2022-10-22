#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 5e5 + 5;
int n,k,ans;
long long f[N],invf[N];
long long qpow(long long a,int x) {
	long long res = 1;
	while(x) {
		if(x & 1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;
}
long long C(int n,int m) {
	if(m < 0 || n < m) return 0;
	return f[n] * invf[m] % MOD * invf[n-m] % MOD;
}
int main() {
	cin >> n >> k;f[0] = 1;
	for(int i = 1;i <= max(n,k);++i)
		f[i] = f[i-1] * i % MOD;
	invf[max(n,k)] = qpow(f[max(n,k)],MOD-2);
	invf[0] = 1;
	for(int i = max(n,k)-1;i >= 1;--i)
		invf[i] = (i+1) * invf[i+1] % MOD;
	for(int i = 1;i <= n;++i)
		ans = (ans + C(n/i - 1,k - 1)) % MOD;
	cout << ans << endl;
	return 0;
}