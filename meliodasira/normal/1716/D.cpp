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

const int P = 998244353;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

const int N = 2e5 + 5;

int dp[N], ndp[N], ans[N];
int n, k;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	k = read();
	int sum = 0;
	dp[0] = 1;
	rep(i, 0, 700) {
		if (sum > n) break;
		memset(ndp, 0, sizeof(ndp));
		rep(j, sum + i + k, n) {
			ndp[j] = add(ndp[j - i - k], dp[j - i - k]);
			ans[j] = add(ans[j], ndp[j]);
		}
		memcpy(dp, ndp, sizeof(ndp));
		sum += i + k;
	}
	rep(i, 1, n) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}