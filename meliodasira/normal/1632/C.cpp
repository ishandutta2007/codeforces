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

int dp[25][2];
int T, a, b, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		a = read();
		b = read();
		ans = abs(a - b);
		for (int i = a; i < b; i++) {
			if (b % 2 == 0) {
				dp[0][0] = i % 2;
				dp[0][1] = i % 2;
			} else {
				dp[0][0] = i % 2;
				dp[0][1] = 1;
			}
			for (int j = 1; j <= 19; j++) {
				if ((b >> j) & 1) {
					dp[j][0] = min(min(dp[j - 1][0], dp[j - 1][1]) + (i & (1 << j)), dp[j - 1][0] + (1 << j));
					dp[j][1] = dp[j - 1][1] + (1 << j);
				} else {
					dp[j][0] = dp[j - 1][0] + (i & (1 << j));
					dp[j][1] = min(min(dp[j - 1][0], dp[j - 1][1]) + (1 << j), dp[j - 1][1] + (i & (1 << j)));
				}
			}
			ans = min(ans, dp[19][1] + 1 + i - a - b);
		}
		printf("%d\n", ans);
	}
}