#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int mod = 1e9 + 7;

void add(int &x,int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int power(int x,int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int fac[N], ifac[N];

int C(int n,int k) {
	if (n < k || k < 0) {
		return 0;
	} else {
		return mul(fac[n], mul(ifac[k], ifac[n - k]));
	}
}

int A(int n,int k) {
	if (n < k || k < 0) {
		return 0;
	} else {
		return mul(fac[n], ifac[n - k]);
	}
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = mul(fac[i - 1], i);
	}
	ifac[N - 1] = power(fac[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i) {
		ifac[i] = mul(ifac[i + 1], i + 1);
	}
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int ans = 0;
	for (int k = 1; k <= n - 1; ++k) {
		int ways = mul(A(n - 2, k - 1), mul(C(m - 1, k - 1), power(m, n - k - 1)));
		if (k + 2 <= n) {
			ways = mul(ways, mul(k + 1, power(n, n - k - 2)));
		}
		add(ans, ways);
	}
	cout << ans << '\n';
}