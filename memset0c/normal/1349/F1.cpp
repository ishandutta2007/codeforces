#include <bits/stdc++.h>

const int N = 5010, mod = 998244353;
int n;

struct z {
	int x;
	z(int x = 0) : x(x) {}
	friend inline z operator*(z a, z b) { return (long long)a.x * b.x % mod; }
	friend inline z operator-(z a, z b) {
		return (a.x -= b.x) < 0 ? a.x + mod : a.x;
	}
	friend inline z operator+(z a, z b) {
		return (a.x += b.x) >= mod ? a.x - mod : a.x;
	}
} ans[N], fac[N], inv[N], ifac[N], g[N][N];
inline z fpow(z a, int b) {
	z s = 1;
	for (; b; b >>= 1, a = a * a)
		if (b & 1) s = s * a;
	return s;
}

void init(int n) {
	fac[0] = ifac[0] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i];
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
}

int main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	std::cin >> n;
	init(n + 5);
	g[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			g[i][j] = g[i - 1][j] * j + g[i - 1][j - 1];
			ans[i - j] = ans[i - j] + g[i][j] * fac[j] * fac[n] * ifac[i];
		}
	}
	for (int i = n - 1; ~i; i--) {
		for (int j = i + 1; j < n; j++)
			ans[i] = ans[i] - fac[j] * ifac[i] * ifac[j - i] * ans[j];
	}
	for (int i = 0; i < n; i++) std::cout << ans[i].x << " ";
	puts("");
}