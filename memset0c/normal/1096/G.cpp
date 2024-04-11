// =================================
//   author: memset0
//   date: 2019.01.13 11:37:52
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 2e6 + 10, mod = 998244353;
int n, m, ans;
int s[11], pre_g[2][30];

inline void print(const std::vector <int> &a) {
	for (auto i : a) print(i, ' '); putchar('\n');
}

inline int fpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1, a = (ll)a * a % mod)
		if (b & 1) s = (ll)s * a % mod;
	return s;
}

int inv(int x) {
	if (!x || x == 1) return 1;
	return (ll)(mod - mod / x) * inv(mod % x) % mod;
}

int f[N << 2], g[N << 2], rev[N << 2];
inline void ntt(int *a, int lim, int flag) {
	for (int i = 0; i < lim; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1, cnt = 1; len < lim; len <<= 1, ++cnt)
		for (int i = 0, wn = pre_g[flag][cnt]; i < lim; i += (len << 1))
			for (int j = 0, w = 1; j < len; j++, w = (ll)w * wn % mod) {
				int x = a[i + j], y = (ll)w * a[i + j + len] % mod;
				a[i + j] = (x + y) % mod, a[i + j + len] = (x - y + mod) % mod;
			}
}

inline std::vector <int> operator * (const std::vector <int> &a, const std::vector <int> &b) {
	int len = 1, k = 0, a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;
	while (len <= (a_size + b_size)) len <<= 1, ++k;
	// printf("   "), print(a), printf(" * "), print(b);
	for (int i = 0; i < len; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
		f[i] = i < a_size ? a[i] : 0;
		g[i] = i < b_size ? b[i] : 0;
	}
	ntt(f, len, 0), ntt(g, len, 0);
	for (int i = 0; i < len; i++) f[i] = (ll)f[i] * g[i] % mod;
	ntt(f, len, 1), len = inv(len); std::vector <int> c(c_size);
	for (int i = 0; i < c_size; i++) c[i] = (ll)f[i] * len % mod;
	// printf(" = "), print(c);
	return c;
}

std::vector <int> fpow(std::vector <int> a, int b) {
	std::vector <int> s; s.push_back(1);
	for (; b; b >>= 1, a = a * a)
		if (b & 1) s = s * a;
	return s;
}

void main() {
	for (int i = 0; i < 30; i++) {
		pre_g[0][i] = fpow(3, (mod - 1) / (1 << i));
		pre_g[1][i] = fpow((998244353 + 1) / 3, (mod - 1) / (1 << i));
	}
	read(n), read(m);
	for (int i = 1; i <= m; i++) read(s[i]);
	std::vector <int> f(10);
	for (int i = 1; i <= m; i++) f[s[i]] = 1;
	f = fpow(f, n >> 1);
	for (size_t i = 0; i < f.size(); i++) ans = (ans + (ll)f[i] * f[i]) % mod;
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }