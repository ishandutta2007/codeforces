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

const int N = 2e5 + 5;

int x[N];
long long v1[N], v2[N];
int T, n, a, b;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		a = read();
		b = read();
		for (int i = 1; i <= n; i++) x[i] = read();
		long long ans = 1e18;
		v2[n + 1] = 0;
		for (int i = 1; i <= n; i++) {
			v1[i] = v1[i - 1] + 1ll * (a + b) * (x[i] - x[i - 1]);
		}
		for (int i = n; i >= 1; i--) {
			v2[i] = v2[i + 1] + x[i];
		}
		ans = min(ans, v2[1] * b);
		for (int i = 1; i <= n; i++) ans = min(ans, v1[i] + (v2[i + 1] - 1ll * x[i] * (n - i)) * b);
		printf("%lld\n", ans);
	}
}