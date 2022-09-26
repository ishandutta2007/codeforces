#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;

int fact[N];
int binpow(int n,int k) {
	int ret = 1;
	while(k) {
		if (k & 1) ret = 1LL * ret * n % mod;
		n = 1LL * n * n % mod;
		k >>= 1;
	}
	return ret;
}

int C(int n,int k) {
	if (n < k) return 0;
	int up = fact[n];
	int down = 1LL * fact[k] * fact[n - k] % mod;
	down = binpow(down,mod - 2);
	return 1LL * up * down % mod;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	fact[0] = 1;
	for (int i = 1;i < N;++i) fact[i] = 1LL * fact[i - 1] * i % mod;
	int n,m,k;
	cin >> n >> m >> k;
	cout << 1LL * C(n - 1,k << 1) * C(m - 1,k << 1) % mod << endl;
}