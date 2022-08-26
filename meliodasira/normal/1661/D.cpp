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

long long a[N], tag1[N], tag2[N], val1, val2, ans;
int n, k;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	k = read();
	rep(i, 1, n) scanf("%lld", &a[i]);
	per(i, n, k + 1) {
		val1 -= tag1[i];
		val2 -= tag2[i];
		long long now = a[i] - val1 * i + val2;
		if (now > 0) {
			long long need = (now - 1) / k + 1;
			ans += need;
			val1 += need;
			val2 += (i - k) * need;
			tag1[i - k] += need;
			tag2[i - k] += (i - k) * need;
		}
	}
	long long maxn = 0;
	per(i, k, 1) {
		val1 -= tag1[i];
		val2 -= tag2[i];
		long long now = a[i] - val1 * i + val2;
		if (now > 0) maxn = max(maxn, (now - 1) / i + 1);
	}
	printf("%lld\n", ans + maxn);
}