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

long long fac[20], n;
int T;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	fac[0] = 1;
	rep(i, 1, 14) fac[i] = fac[i - 1] * i;
	T = read();
	while (T--) {
		scanf("%lld", &n);
		int ans = 1e9;
		for (int i = 0; i < (1 << 12); i++) {
			long long now = n;
			for (int j = 0; j < 12; j++) {
				if ((i >> j) & 1) {
					now -= fac[j + 3];
				}
			}
			if (now >= 0) ans = min(ans, __builtin_popcount(i) + __builtin_popcountll(now));
		}
		printf("%d\n", ans);
	}
}