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

const int N = 5e5 + 5;

int mx[N << 2];
int a[N], dp[N], maxn[N];
long long s[N], b[N];
int T, n;

void modify(int u, int l, int r, int x, int y) {
	if (l == r) {
		mx[u] = max(mx[u], y);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= x)
		modify(u << 1, l, mid, x, y);
	else
		modify(u << 1 | 1, mid + 1, r, x, y);
	mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
}

int query(int u, int L, int R, int l, int r) {
	if (l > r) return -1e9;
	if (l <= L && R <= r) return mx[u];
	int mid = (L + R) >> 1, ans = -1e9;
	if (mid >= l) ans = max(ans, query(u << 1, L, mid, l, r));
	if (mid + 1 <= r) ans = max(ans, query(u << 1 | 1, mid + 1, R, l, r));
	return ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read(), s[i] = s[i - 1] + a[i];
		for (int i = 0; i <= n; i++) b[i] = s[i], maxn[i] = -1e9;
		sort(b, b + n + 1);
		for (int i = 1; i <= (n + 1) * 4; i++) mx[i] = -1e9;
		for (int i = 0; i <= n; i++) {
			int pos = lower_bound(b, b + n + 1, s[i]) - b;
			if (i == 0) {
				dp[i] = 0;
			} else {
				dp[i] = max(dp[i - 1] - 1, max(query(1, 0, n, 0, pos - 1) + i, maxn[pos]));
			}
			modify(1, 0, n, pos, dp[i] - i);
			maxn[pos] = max(maxn[pos], dp[i]);
		}
		printf("%d\n", dp[n]);
	}
}