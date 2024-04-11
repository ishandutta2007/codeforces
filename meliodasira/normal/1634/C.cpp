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

const int N = 505;

int ans[N][N];
int T, n, k;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		k = read();
		int x = 1, y = 2;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				for (int j = 1; j <= k; j++) {
					ans[i][j] = x;
					x += 2;
				}
			} else {
				for (int j = 1; j <= k; j++) {
					ans[i][j] = y;
					y += 2;
				}
			}
		}
		if (x <= n * k + 2 && y <= n * k + 2) {
			printf("YES\n");
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= k; j++) {
					printf("%d ", ans[i][j]);
				}
				printf("\n");
			}
		} else {
			printf("NO\n");
		}
	}
}