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

int fac[65], inv[65];
int T, n;

inline void upd(int& x, int y) {
	x = add(x, y);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	fac[0] = inv[0] = 1;
	rep(i, 1, 60) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[i - 1], fpow(i, P - 2));
	}
	auto C = [&](int n, int m) {
		if (n < m || m < 0) return 0;
		return mul(fac[n], mul(inv[m], inv[n - m]));
	};
	T = read();
	while (T--) {
		n = read();
		int ans1 = 0, ans2 = 0, ans3 = 0;
		for (int i = n, cur = 0; i >= 2; i -= 2, cur ^= 1) {
			if (cur == 0) {
				upd(ans1, C(i - 1, i / 2));
				upd(ans2, C(i - 2, i / 2));
			} else {
				upd(ans2, C(i - 1, i / 2));
				upd(ans1, C(i - 2, i / 2));
			}
		}
		ans3 = sub(C(n, n / 2), add(ans1, ans2));
		printf("%d %d %d\n", ans1, ans2, ans3);
	}
}