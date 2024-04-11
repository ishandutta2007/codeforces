#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 5;
const int MOD = 998244353;


LL f[N];
LL power (LL x, LL y) {
	LL ret = 1;
	for ( x %= MOD; y ; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

void work() {
	int n;
	vector <int> a;
	read(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x; read(x);
		a.push_back(x); sum += x;
	}
	int cnt = 0;
	for (int i = 0; i < n - sum; i++) cnt += a[i];

	printf("%lld\n", f[cnt] * ((LL) n * (n - 1ll) / 2 % MOD) % MOD);
}



int main() {

	f[0] = 0;
	for (int i = 1; i < N; i++) f[i] = (f[i - 1] + power((LL)i * i % MOD, MOD - 2)) % MOD;

	int T;
	read(T);
	while (T--) work();
}