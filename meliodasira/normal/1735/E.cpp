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

#define int long long
const int N = 1005;

map<int, int> cnt;
int a[N], b[N], vis[N];
int T, n;

bool check(int x) {
	cnt.clear();
	rep(i, 1, n)++ cnt[b[i]];
	per(i, n, 1) {
		if (cnt.count(a[i] + x) && cnt[a[i] + x]) {
			--cnt[a[i] + x];
			vis[i] = 1;
			continue;
		}
		if (cnt.count(a[i] - x) && cnt[a[i] - x]) {
			--cnt[a[i] - x];
			vis[i] = 2;
			continue;
		}
		if (cnt.count(x - a[i]) && cnt[x - a[i]]) {
			--cnt[x - a[i]];
			vis[i] = 2;
			continue;
		}
		return 0;
	}
	printf("YES\n");
	int p = 1e9;
	if (x > p) p = 0;
	rep(i, 1, n) {
		int val;
		if (vis[i] == 1) val = p - a[i];
		if (vis[i] == 2) val = p + a[i];
		printf("%lld%c", val, i == n ? '\n' : ' ');
	}
	printf("%lld %lld\n", p, p + x);
	return 1;
}

signed main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 1, n) b[i] = read();
		sort(a + 1, a + n + 1);
		int ok = 0;
		rep(i, 1, n) {
			if (check(a[1] + b[i])) {
				ok = 1;
				break;
			}
			if (check(abs(a[1] - b[i]))) {
				ok = 1;
				break;
			}
		}
		if (!ok) printf("NO\n");
	}
}