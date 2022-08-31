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

int ans[N][N], a[N][N], ban[N * N], px[N * N], py[N * N];
int n, k, maxn;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	k = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
			px[a[i][j]] = i;
			py[a[i][j]] = j;
			ans[i][j] = 1;
		}
	}
	int l1 = 2, r1 = n * 2, l2 = 1 - n, r2 = n - 1;
	for (int i = 1; i <= n * n; i++) ban[i] = 0;
	maxn = n * n;
	while (maxn) {
		int i = px[maxn], j = py[maxn];
		ban[a[i][j]] = 1;
		ans[i][j] = 0;
		while (i + j - l1 > k) {
			for (int x = 1; x <= n; x++) {
				int y = l1 - x;
				if (x >= 1 && y >= 1 && x <= n && y <= n) {
					ban[a[x][y]] = 1;
				}
			}
			++l1;
		}
		while (r1 - (i + j) > k) {
			for (int x = 1; x <= n; x++) {
				int y = r1 - x;
				if (x >= 1 && y >= 1 && x <= n && y <= n) {
					ban[a[x][y]] = 1;
				}
			}
			--r1;
		}
		while (i - j - l2 > k) {
			for (int x = 1; x <= n; x++) {
				int y = x - l2;
				if (x >= 1 && y >= 1 && x <= n && y <= n) {
					ban[a[x][y]] = 1;
				}
			}
			++l2;
		}
		while (r2 - (i - j) > k) {
			for (int x = 1; x <= n; x++) {
				int y = x - r2;
				if (x >= 1 && y >= 1 && x <= n && y <= n) {
					ban[a[x][y]] = 1;
				}
			}
			--r2;
		}
		while (maxn && ban[maxn]) --maxn;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			putchar(ans[i][j] ? 'G' : 'M');
		}
		putchar('\n');
	}
}