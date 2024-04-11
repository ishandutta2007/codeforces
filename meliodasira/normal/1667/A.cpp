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

const int N = 5005;

int a[N];
int n;
long long ans = 1e18;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) {
		long long now = 0, sum = 0;
		for (int j = i - 1; j >= 1; j--) {
			long long cnt = now / a[j] + 1;
			now = a[j] * cnt;
			sum += cnt;
		}
		now = 0;
		for (int j = i + 1; j <= n; j++) {
			long long cnt = now / a[j] + 1;
			now = a[j] * cnt;
			sum += cnt;
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
}