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

int lcp[N][N];
bool pre[N][N], suf[N][N];
char a[N], b[N];
int T, n, m, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		scanf("%s%s", a + 1, b + 1);
		for (int i = 0; i <= n + 1; i++) pre[i][0] = suf[i][m + 1] = 1;
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == b[j])
					pre[i][j] = pre[i - 1][j - 1];
				else
					pre[i][j] = pre[i - 1][j];
			}
		}
		for (int j = m; j >= 1; j--) {
			for (int i = n; i >= 1; i--) {
				if (a[i] == b[j])
					suf[i][j] = suf[i + 1][j + 1];
				else
					suf[i][j] = suf[i + 1][j];
			}
		}
		if (!pre[n][m]) {
			printf("-1\n");
			continue;
		}
		for (int i = 1; i <= n + 1; i++) lcp[i][m + 1] = 0;
		for (int i = 1; i <= m + 1; i++) lcp[n + 1][i] = 0;
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (a[i] == b[j])
					lcp[i][j] = lcp[i + 1][j + 1] + 1;
				else
					lcp[i][j] = 0;
			}
		}
		ans = n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (lcp[i][j] && pre[i - 1][j - 1] && suf[i + lcp[i][j]][j + lcp[i][j]]) {
					int res = n - i + 1 - lcp[i][j];
					if (i != 1) res += (i - 1 - (j - 1)) + i - 1 + 1;
					ans = min(ans, res);
				}
			}
		}
		printf("%d\n", ans);
	}
}