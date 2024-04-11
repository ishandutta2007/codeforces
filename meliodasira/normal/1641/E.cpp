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

const int N = 3e5 + 5;

vector<int> F, G;
int p[N], s[N], res[N * 2], pw[N], ipw[N], a[N];
int n, m, ans;

void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	F.resize(mid - l + 1);
	G.resize(r - mid);
	for (int i = l; i <= mid; i++) F[i - l] = pw[s[i]];
	for (int i = mid + 1; i <= r; i++) G[i - mid - 1] = ipw[s[i]];
	F = F * G;
	for (int i = 0; i < (int)F.size(); i++) res[i + l + mid + 1] = add(res[i + l + mid + 1], F[i]);
	solve(l, mid);
	solve(mid + 1, r);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	pw[0] = ipw[0] = 1;
	rep(i, 1, m) {
		pw[i] = mul(pw[i - 1], 2);
		ipw[i] = mul(ipw[i - 1], (P + 1) / 2);
	}
	rep(i, 1, n) a[i + n] = read();
	rep(i, 1, m) {
		p[i] = read() + n;
		++s[p[i]];
	}
	rep(i, 1, n * 3) s[i] += s[i - 1];
	solve(0, n * 3);
	rep(i, n + 1, 2 * n) {
		int tmp = res[i * 2 - 1];
		tmp = sub(tmp, mul(ipw[m], min(i, 3 * n - i + 1)));
		ans = add(ans, mul(a[i], tmp));
	}
	ans = mul(ans, fpow(2, m));
	ans = mul(ans, fpow(fpow(2, m) - 1, P - 2));
	printf("%d\n", ans);
}