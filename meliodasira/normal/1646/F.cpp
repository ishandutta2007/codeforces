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

const int N = 105;

int a[N][N], val[N][N], sum[N], id[N], ta[N], tv[N];
int n, allsum;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
			val[i][j] = (a[i][j] - i + n) % n;
			sum[i] += val[i][j];
		}
		allsum += sum[i];
	}
	for (int i = 1; i <= n * (n - 1) - allsum / n; i++) {
		int x = 1;
		for (int j = 1; j <= n; j++) {
			if (sum[j] < sum[x]) {
				x = j;
			}
		}
		int y = 1;
		for (int j = 1; j <= n; j++) {
			if (val[x][j] < val[x][y]) {
				y = j;
			}
		}
		val[x][y] += n;
		sum[x] += n;
	}
	printf("%d\n", n * (n - 1));
	for (int _ = 1; _ <= n * (n - 1); _++) {
		for (int i = 1; i <= n; i++) {
			id[i] = 1;
			for (int j = 1; j <= n; j++) {
				if (val[i][j] > val[i][id[i]]) {
					id[i] = j;
				}
			}
			ta[i] = a[i][id[i]];
			tv[i] = val[i][id[i]];
			printf("%d%c", ta[i], i == n ? '\n' : ' ');
		}
		for (int i = 1; i <= n; i++) {
			a[i % n + 1][id[i % n + 1]] = ta[i];
			val[i % n + 1][id[i % n + 1]] = tv[i] - 1;
		}
	}
}