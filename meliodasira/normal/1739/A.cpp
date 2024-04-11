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

int T, n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		int x = 1, y = 1;
		rep(i, 1, n) rep(j, 1, m) {
			int ok = 1;
			if (i - 2 >= 1 && j - 1 >= 1) ok = 0;
			if (i - 1 >= 1 && j - 2 >= 1) ok = 0;
			if (i - 2 >= 1 && j + 1 <= m) ok = 0;
			if (i - 1 >= 1 && j + 2 <= m) ok = 0;
			if (i + 2 <= n && j - 1 >= 1) ok = 0;
			if (i + 1 <= n && j - 2 >= 1) ok = 0;
			if (i + 2 <= n && j + 1 <= m) ok = 0;
			if (i + 1 <= n && j + 2 <= m) ok = 0;
			if (ok) x = i, y = j;
		}
		printf("%d %d\n", x, y);
	}
}