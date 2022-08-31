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

int a[N], tag[N], ans[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		long long sum = 0;
		for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i], tag[i] = 0;
		sum /= n;
		int now = 0;
		for (int i = n; i >= 1; i--) {
			++tag[i - sum];
			++now;
			now -= tag[i];
			int val = a[i] - now;
			if (val) {
				ans[i] = 1;
				--sum;
			} else {
				ans[i] = 0;
			}
		}
		if (sum) ans[1] = 1;
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
}