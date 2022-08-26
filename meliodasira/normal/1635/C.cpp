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

int a[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) a[i] = read();
		int pos = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] > a[i + 1]) {
				pos = i;
				break;
			}
		}
		if (!pos) {
			printf("0\n");
			continue;
		}
		if (pos >= n - 1) {
			printf("-1\n");
			continue;
		}
		if (a[pos + 1] - a[n] > a[pos + 1]) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", pos);
		for (int i = pos; i >= 1; i--) {
			printf("%d %d %d\n", i, i + 1, n);
		}
	}
}