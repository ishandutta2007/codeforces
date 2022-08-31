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

int a[N], cnt[N][N], mx[N][N], dp[N];
int T, n, ans;

bool check(int l, int r) {
	if ((r - l + 1) & 1) return 0;
	if (mx[l][r] * 2 > r - l + 1) return 0;
	return 1;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		memset(dp, -1, sizeof(dp));
		n = read();
		ans = 0;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) {
			memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
			++cnt[i][a[i]];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				mx[i][j] = max(mx[i][j - 1], cnt[j][a[j]] - cnt[i - 1][a[j]]);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (check(1, i - 1)) dp[i] = max(dp[i], 1);
			for (int j = 1; j < i; j++) {
				if (dp[j] != -1 && check(j + 1, i - 1) && a[j] == a[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (dp[i] != -1 && check(i + 1, n)) ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
}