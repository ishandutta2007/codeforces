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

int dp[N][2][3];
char c[2][N];
int n, ans;

inline void upd(int& x, int y) { x = max(x, y); }

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	memset(dp, -1, sizeof(dp));
	n = read();
	scanf("%s%s", c[0] + 1, c[1] + 1);
	dp[0][0][0] = 0;
	rep(i, 0, n - 1) {
		rep(j, 0, 1) {
			rep(k, 0, 2) {
				if (dp[i][j][k] == -1) continue;
				int now = dp[i][j][k];
				rep(x, 0, 3) {
					if (k && (x & k) == k) continue;
					if ((x & 1) && c[0][i + 1] == '0') continue;
					if ((x & 2) && c[1][i + 1] == '0') continue;
					int go = now;
					if (x & 1) ++go;
					if (x & 2) ++go;
					if (x & ((j ^ 1) + 1))
						upd(dp[i + 1][j ^ 1][j + 1], go);
					else
						upd(dp[i + 1][j][0], go);
				}
			}
		}
	}
	rep(i, 0, 1) rep(j, 0, 2) ans = max(ans, dp[n][i][j]);
	printf("%d\n", ans);
}