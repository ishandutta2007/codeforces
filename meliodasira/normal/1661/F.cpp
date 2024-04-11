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

int a[N];
int n;
long long m;

long long calc(int x, int y) {
	int cnt1 = x % y, cnt0 = y - cnt1;
	return 1ll * cnt0 * (x / y) * (x / y) + 1ll * cnt1 * (x / y + 1) * (x / y + 1);
}

pair<long long, long long> calc(long long x) {
	long long ans1 = 0, ans2 = 0;
	rep(i, 1, n) {
		int l = 2, r = a[i] - a[i - 1], res = 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (calc(a[i] - a[i - 1], mid - 1) - calc(a[i] - a[i - 1], mid) >= x)
				res = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		ans1 += calc(a[i] - a[i - 1], res);
		ans2 += (res - 1);
	}
	return make_pair(ans1, ans2);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	rep(i, 1, n) a[i] = read();
	scanf("%lld", &m);
	long long l = 1, r = 1e18, res = 0;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		pair<long long, long long> val = calc(mid);
		if (val.first <= m)
			res = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	pair<long long, long long> val = calc(res);
	val.second -= (m - val.first) / res;
	printf("%lld\n", val.second);
}