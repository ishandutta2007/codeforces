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

const int N = 1e6 + 5;

int a[N];
int T, n, k;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		k = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] >= i) {
				ans = 0;
			}
		}
		for (int i = n - k + 1; i <= n; i++) {
			if (a[i] > 0) {
				ans = 0;
			}
		}
		if (!ans) {
			printf("0\n");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			int now = 0;
			if (i <= k) {
				now = i;
			} else {
				if (a[i - k] == 0) {
					now = min(k, i - 1) + 1;
				}
				if (a[i - k] > 0) {
					now = 1;
				}
				if (a[i - k] == -1) {
					now = min(k, i - 1) + 1;
					if (k + 1 <= i - 1) now += i - k - 1;
				}
			}
			ans = mul(ans, now);

			// fprintf(stderr, "i = %d, now = %d\n", i, now);
		}
		printf("%d\n", ans);
	}
}