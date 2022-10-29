#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

inline int norm(int x) {
	return x >= mod ? x - mod : x;
}

inline int reduce(int x) {
	return x < 0 ? x + mod : x;
}

int mpow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		y >>= 1; x = 1ll * x * x % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	if (k == 0) {
		cout << 1 << endl;
		return 0;
	}
	vector<char> c(n + 1);
	vector<int> pos(1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == '1') pos.push_back(i);
	}
	pos.push_back(n + 1);
	vector<int> fac(n + 1), inv(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = mpow(fac[n], mod - 2);
	for (int i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % mod;
	auto binom = [&](int n, int m) {
		if (n < m || m < 0) return 0;
		return (int)(1ll * fac[n] * inv[m] % mod * inv[n - m] % mod);
	};
	if ((int)pos.size() - 2 < k) {
		cout << 1 << endl;
		return 0;
	}
	int ans = binom(pos[k + 1] - pos[0] - 1, k);
	for (int i = 2; i <= (int)pos.size() - k - 1; i++) {
		ans = norm(ans + binom(pos[i + k] - pos[i - 1] - 1, k));
		ans = reduce(ans - binom(pos[i + k - 1] - pos[i - 1] - 1, k - 1));
	}
	cout << ans << endl;
	return 0;
}