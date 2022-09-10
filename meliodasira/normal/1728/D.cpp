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

const int N = 2005;

char c[N];
int dp[N][N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		scanf("%s", c + 1);
		n = strlen(c + 1);
		for (int i = 1; i <= n - 1; i++) {
			if (c[i] == c[i + 1])
				dp[i][i + 1] = 0;
			else
				dp[i][i + 1] = 1;
		}
		for (int len = 4; len <= n; len += 2) {
			for (int l = 1; l <= n - len + 1; l++) {
				int r = l + len - 1;
				dp[l][r] = -1;
				// choose l
				int ret = 1;
				if (dp[l + 1][r - 1] != 0)
					ret = min(ret, dp[l + 1][r - 1]);
				else if (c[r] < c[l])
					ret = -1;
				else if (c[r] == c[l])
					ret = min(ret, 0);
				if (dp[l + 2][r] != 0)
					ret = min(ret, dp[l + 2][r]);
				else if (c[l + 1] < c[l])
					ret = -1;
				else if (c[l + 1] == c[l])
					ret = min(ret, 0);
				dp[l][r] = max(dp[l][r], ret);
				ret = 1;
				if (dp[l + 1][r - 1] != 0)
					ret = min(ret, dp[l + 1][r - 1]);
				else if (c[l] < c[r])
					ret = -1;
				else if (c[l] == c[r])
					ret = min(ret, 0);
				if (dp[l][r - 2] != 0)
					ret = min(ret, dp[l][r - 2]);
				else if (c[r - 1] < c[r])
					ret = -1;
				else if (c[r - 1] == c[r])
					ret = min(ret, 0);
				dp[l][r] = max(dp[l][r], ret);
			}
		}
		if (dp[1][n] == 1)
			printf("Alice\n");
		else if (dp[1][n] == 0)
			printf("Draw\n");
		else
			printf("Bob\n");
	}
}