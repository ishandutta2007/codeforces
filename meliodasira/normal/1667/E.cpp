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

const int md = 998244353;

inline int add(int x, int y) {
	if (x + y >= md) return x + y - md;
	return x + y;
}

inline void addx(int& x, int y) {
	x += y;
	if (x >= md) x -= md;
}

inline int sub(int x, int y) {
	if (x < y) return x - y + md;
	return x - y;
}

inline void subx(int& x, int y) {
	x -= y;
	if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
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
			int wn = fpow(3, (md - 1) / (mid << 1));
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
		if ((int)a.size() <= 64 && (int)b.size() <= 64) {
			vector<int> ans(a.size() + b.size() - 1, 0);
			for (int i = 0; i < (int)a.size(); i++) {
				for (int j = 0; j < (int)b.size(); j++) {
					ans[i + j] = add(ans[i + j], mul(a[i], b[j]));
				}
			}
			return ans;
		}
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
		int inv = fpow(1 << base, md - 2);
		for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
		return a;
	}

	vector<int> tmp;

	vector<int> pmul(vector<int> a, vector<int> b, int n, int ntted = 0) {
		int base = 0;
		while ((1 << base) < n) ++base;
		getRevRoot(base);
		a.resize(1 << base);
		ntt(a, base);
		if (!ntted) b.resize(1 << base), ntt(b, base), tmp = b;
		for (int i = 0; i < (1 << base); i++) a[i] = mul(a[i], tmp[i]);
		ntt(a, base);
		reverse(a.begin() + 1, a.end());
		a.resize(n);
		int inv = fpow(1 << base, md - 2);
		for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
		return a;
	}

	vector<int> polyInv(vector<int> a, int n) {
		a.resize(n);
		if (n == 1) {
			vector<int> ans(1, fpow(a[0], md - 2));
			return ans;
		}
		vector<int> f0 = polyInv(a, (n + 1) >> 1), ans = f0;
		vector<int> now = pmul(a, f0, n, 0);
		for (int i = 0; i < (int)f0.size(); i++) now[i] = 0;
		now = pmul(now, vector<int>(0), n, 1);
		ans.resize(n);
		for (int i = (int)f0.size(); i < n; i++) ans[i] = sub(0, now[i]);
		return ans;
	}

	vector<int> polyInv(vector<int> a) {
		return polyInv(a, (int)a.size());
	}

	vector<int> operator+(vector<int> a, vector<int> b) {
		if (a.size() < b.size()) a.resize(b.size());
		for (int i = 0; i < (int)b.size(); i++) a[i] = add(a[i], b[i]);
		return a;
	}

	vector<int> operator-(vector<int> a, vector<int> b) {
		if (a.size() < b.size()) a.resize(b.size());
		for (int i = 0; i < (int)b.size(); i++) a[i] = sub(a[i], b[i]);
		return a;
	}

	vector<int> diff(vector<int> f) {
		int n = (int)f.size() - 1;
		for (int i = 0; i < n; i++) f[i] = mul(f[i + 1], i + 1);
		f.resize(n);
		return f;
	}

	vector<int> inte(vector<int> f) {
		int n = (int)f.size() + 1;
		f.resize(n);
		for (int i = n - 1; i >= 1; i--) f[i] = mul(f[i - 1], fpow(i, md - 2));
		f[0] = 0;
		return f;
	}

	vector<int> polyLn(vector<int> f) {
		int n = (int)f.size();
		f = inte(diff(f) * polyInv(f));
		f.resize(n);
		return f;
	}

	vector<int> polyExp(vector<int> f, int base) {
		int n = 1 << base;
		f.resize(n);
		if (n == 1) {
			vector<int> ans(1, 1);
			return ans;
		}
		vector<int> g0 = polyExp(f, base - 1), g(1, 1);
		g0.resize(n);
		g = g0 * (g - polyLn(g0) + f);
		return g;
	}

	vector<int> polyExp(vector<int> f) {
		int n = (int)f.size(), base = 0;
		while ((1 << base) < n) ++base;
		f = polyExp(f, base);
		f.resize(n);
		return f;
	}
}

using Poly::operator*;

const int N = 2e5 + 5;

int f[N], ans[N], sinv[N], fac[N], inv[N], invv[N];
int n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
	inv[n] = fpow(fac[n], md - 2);
	for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
	for (int i = 1; i <= n; i++) invv[i] = mul(fac[i - 1], inv[i]);
	for (int i = 1; i <= n; i++) sinv[i] = add(sinv[i - 1], invv[i]);
	for (int i = 1; i <= n; i++) {
		f[i] = fac[i];
		if (i >= n / 2 + 1) f[i] = sub(f[i], mul(fac[i], sub(sinv[i], sinv[n / 2])));
	}
	vector<int> F, G;
	F.resize(n / 2 + 2);
	G.resize(n / 2 + 2);
	for (int i = 2; i <= n / 2 + 1; i++) F[i] = mul(fac[i - 2], mul(inv[n - i], f[n - i]));
	for (int i = 0; i <= n / 2 + 1; i++) G[i] = inv[i];
	reverse(G.begin(), G.end());
	F = F * G;
	for (int i = 2; i <= n / 2 + 1; i++) ans[i] = mul(i - 1, mul(fac[n - i], F[n / 2 + 1 + i]));
	ans[1] = fac[n - 1];
	for (int i = 2; i <= n / 2 + 1; i++) ans[1] = sub(ans[1], ans[i]);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}