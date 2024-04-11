#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int P = 998244353;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

namespace Poly {
	vector<int> roots, rev;

	void getRevRoot(int base) {
		int n = 1 << base;
		if ((int)rev.size() == n) return;
		rev.resize(n);
		for (int i = 1; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base - 1));
		if ((int)roots.size() >= n) return;
		int pren = max(1, (int)roots.size());
		roots.resize(n);
		for (int mid = pren; mid < n; mid <<= 1) {
			int wn = fpow(3, (P - 1) / (mid << 1));
			roots[mid] = 1;
			for (int i = 1; i < mid; i++) roots[i + mid] = mul(roots[i + mid - 1], wn);
		}
	}

	void ntt(vector<int>& a, int base) {
		int n = 1 << base;
		for (int i = 0; i < n; i++) {
			if (i < rev[i]) {
				swap(a[i], a[rev[i]]);
			}
		}
		for (int mid = 1; mid < n; mid <<= 1) {
			for (int i = 0; i < n; i += (mid << 1)) {
				for (int j = 0; j < mid; j++) {
					int x = a[i + j], y = mul(a[i + j + mid], roots[mid + j]);
					a[i + j] = add(x, y);
					a[i + j + mid] = sub(x, y);
				}
			}
		}
	}

	vector<int> operator*(vector<int> a, vector<int> b) {
		int n = (int)a.size() + (int)b.size() - 1, base = 0;
		while ((1 << base) < n) ++base;
		a.resize(1 << base);
		b.resize(1 << base);
		getRevRoot(base);
		ntt(a, base);
		ntt(b, base);
		for (int i = 0; i < (1 << base); i++) a[i] = mul(a[i], b[i]);
		reverse(a.begin() + 1, a.end());
		ntt(a, base);
		a.resize(n);
		int inv = fpow(1 << base, P - 2);
		for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
		return a;
	}
}

using Poly::operator*;

const int N = 2e5 + 5;

vector<int> f, g;
int mu[N], fac[N], inv[N], res[N], vis[N];
int n, k, ans;

void calc(int m) {
	if (vis[m]) return;
	vis[m] = 1;
	f.resize(m + 1);
	g.resize(m + 1);
	for (int i = 1; i <= m; i++) f[i] = mul(fpow(i, m), inv[i]);
	for (int i = 0; i <= m; i++) g[i] = (i & 1) ? sub(0, inv[i]) : inv[i];
	f = f * g;
	int sum = 0;
	for (int i = 0; i <= min(m, k); i++) sum = add(sum, f[i]);
	res[m] = sum;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	k = read();
	if (n == 1 || k == 1) {
		printf("1\n");
		return 0;
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
	inv[n] = fpow(fac[n], P - 2);
	for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	mu[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i * 2; j <= n; j += i) mu[j] -= mu[i];
	}
	for (int i = 1; i <= n; i++) {
		if (!mu[i]) continue;
		int m = (n + i - 1) / i;
		calc(m);
		if (mu[i] == 1)
			ans = add(ans, sub(res[m], 1));
		else
			ans = sub(ans, sub(res[m], 1));
	}
	printf("%d\n", ans);
}