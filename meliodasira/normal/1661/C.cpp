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

const int N = 3e5 + 5;

int a[N];
int T, n;

long long calc(int x) {
	long long cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		cnt1 += ((x - a[i]) % 2);
		cnt2 += ((x - a[i]) / 2);
	}
	long long cnt = 0;
	if (cnt2 >= cnt1 + 2) cnt = (cnt2 - cnt1 - 2) / 3 + 1;
	return max((cnt1 + 2 * cnt) * 2 - 1, (cnt2 - cnt) * 2);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		int maxn = 0;
		long long ans = 1e18;
		rep(i, 1, n) a[i] = read(), maxn = max(maxn, a[i]);
		rep(i, 0, 3) ans = min(ans, calc(maxn + i));
		printf("%lld\n", ans);
	}
}