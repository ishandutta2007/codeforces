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

int a[N], s[N], mx[N];
int T, n, x;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		memset(mx, -0x7f, sizeof(mx));
		n = read();
		x = read();
		for (int i = 1; i <= n; i++) a[i] = read(), s[i] = s[i - 1] + a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				mx[j - i + 1] = max(mx[j - i + 1], s[j] - s[i - 1]);
			}
		}
		for (int i = 0; i <= n; i++) {
			int ans = 0;
			for (int j = 1; j <= n; j++) ans = max(ans, mx[j] + min(j, i) * x);
			printf("%d%c", ans, i == n ? '\n' : ' ');
		}
	}
}