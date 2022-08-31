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

const int N = 1e5 + 5, MAGIC = 300, L = N / MAGIC + 3;

int a[N], b[N], cnt[N];
int n, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, -MAGIC, MAGIC) {
		rep(j, 1, n) b[j] = a[j] - j * i;
		sort(b + 1, b + n + 1);
		int maxn = 0;
		for (int l = 1, r; l <= n; l = r + 1) {
			r = l;
			while (r < n && b[r + 1] == b[l]) ++r;
			maxn = max(maxn, r - l + 1);
		}
		ans = max(ans, maxn);
	}
	rep(i, 1, n) {
		int len = 0;
		rep(j, max(1, i - L), min(n, i + L)) {
			if (i == j) continue;
			if ((a[i] - a[j]) % (i - j) == 0) {
				b[++len] = (a[i] - a[j]) / (i - j);
			}
		}
		sort(b + 1, b + len + 1);
		int maxn = 0;
		for (int l = 1, r; l <= len; l = r + 1) {
			r = l;
			while (r < len && b[r + 1] == b[l]) ++r;
			maxn = max(maxn, r - l + 1);
		}
		ans = max(ans, maxn + 1);
	}
	printf("%d\n", n - ans);
}