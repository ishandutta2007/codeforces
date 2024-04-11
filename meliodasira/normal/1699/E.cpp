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

const int mod[2] = { 1000000007, 1000000009 };

const int N = 5e6 + 5;

int dp[2][N], vis[N];
int T, n, m, cnt, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		cnt = 0;
		ans = m - 1;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= 1; j++) dp[j][i] = 0;
			vis[i] = 0;
		}
		for (int i = 0; i <= 1; i++) dp[i][1] = 1;
		for (int i = 1; i <= n; i++) {
			int x = read();
			if (!vis[x]) vis[x] = 1, ++cnt;
		}
		for (int i = 2, j = 1, now = vis[1]; i <= m; i++) {
			while (j < m && now < cnt) {
				++j;
				for (int k = 1; k <= m / j; k++) {
					int ok0 = 1, ok1 = 0;
					for (int t = 0; t <= 1; t++) {
						if (dp[t][k * j]) ok0 = 0;
						dp[t][k * j] += dp[t][k];
						if (dp[t][k * j] >= mod[t]) dp[t][k * j] -= mod[t];
						if (dp[t][k * j]) ok1 = 1;
					}
					if (ok0 && ok1 && vis[k * j]) ++now;
				}
			}
			if (now < cnt) break;
			if (vis[1]) {
				ans = j - 1;
				break;
			}
			ans = min(ans, j - i);
			for (int k = m / i; k >= 1; k--) {
				int ok0 = 0, ok1 = 1;
				for (int t = 0; t <= 1; t++) {
					if (dp[t][k * i]) ok0 = 1;
					dp[t][k * i] -= dp[t][k];
					if (dp[t][k * i] < 0) dp[t][k * i] += mod[t];
					if (dp[t][k * i]) ok1 = 0;
				}
				if (ok0 && ok1 && vis[k * i]) --now;
			}
		}
		printf("%d\n", ans);
	}
}