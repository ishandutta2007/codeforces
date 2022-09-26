#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int mod = 998244353;

void add(int& x,int y) {
	x += y; if (x >= mod) x -= mod;
}

void sub(int& x,int y) {
	x -= y; if (x < 0) x += mod;
}

int mul(int x,int y) {
	return 1LL * x * y % mod;
}

int pw(int x,int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mul(res, x);
		x = mul(x, x);
		y >>= 1;
	}
	return res;
}

int n;
int fac[N], ifac[N];

int A(int n,int k) {
	if (n < k || k < 0) return 0;
	return mul(fac[n], ifac[n - k]);
}

int C(int n,int k) {
	if (n < k || k < 0) return 0;
	return mul(fac[n], mul(ifac[k], ifac[n - k]));
}

int main() {
	scanf("%d", &n);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = mul(fac[i - 1], i);
	}
	ifac[n] = pw(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) {
		ifac[i] = mul(ifac[i + 1], i + 1);
	}
	int ans = fac[n];
	for (int i = 1; i <= n - 1; ++i) {
		add(ans, mul(A(n, i), fac[n - i] + mod - 1));
	}
	printf("%d\n", ans);
}