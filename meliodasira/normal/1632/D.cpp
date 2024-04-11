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

int st[N][19], a[N], lg[N], r[N], ban[N], ans[N];
int n, minn;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int query(int l, int r) {
	int k = lg[r - l + 1];
	return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), st[i][0] = a[i];
	for (int j = 1; j <= 18; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	lg[0] = -1;
	for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; i++) {
		int l = i + 1, r = n, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query(i, mid) >= mid - i + 1)
				res = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		if (query(i, res) == res - i + 1) ::r[i] = res;
	}
	int minn = n + 1;
	for (int i = n; i >= 1; i--) {
		if (!r[i]) continue;
		if (minn < r[i]) ban[i] = 1;
		minn = min(minn, r[i]);
	}
	int now = 0;
	for (int i = 1; i <= n; i++) {
		if (!r[i] || ban[i]) continue;
		if (now < i) {
			ans[r[i]] = 1;
			now = r[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[i] += ans[i - 1];
		printf("%d ", ans[i]);
	}
}