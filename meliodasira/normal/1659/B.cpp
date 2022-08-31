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
int a[N], ans[N];
int T, n, k;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		k = read();
		scanf("%s", c + 1);
		for (int i = 1; i <= n; i++) a[i] = (c[i] - '0') ^ (k & 1), ans[i] = 0;
		for (int i = 1; i <= n; i++) {
			if (!a[i] && k) {
				a[i] = 1;
				--k;
				ans[i] = 1;
			}
		}
		ans[n] += k;
		if (k & 1) a[n] ^= 1;
		for (int i = 1; i <= n; i++) printf("%d", a[i]);
		putchar('\n');
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
}