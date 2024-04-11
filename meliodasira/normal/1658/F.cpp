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

char c[N];
int s[N];
int T, n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		scanf("%s", c + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (c[i] - '0');
		if (1ll * s[n] * m % n != 0) {
			printf("-1\n");
			continue;
		}
		int need = 1ll * s[n] * m / n, ans = 0;
		for (int i = 1; i <= n - m + 1; i++) {
			if (s[i + m - 1] - s[i - 1] == need) {
				printf("1\n%d %d\n", i, i + m - 1);
				ans = 1;
				break;
			}
		}
		if (ans) continue;
		for (int i = 1; i <= m; i++) {
			if (s[i] + s[n] - s[n - (m - i)] == need) {
				printf("2\n%d %d\n%d %d\n", 1, i, n - (m - i) + 1, n);
				break;
			}
		}
	}
}