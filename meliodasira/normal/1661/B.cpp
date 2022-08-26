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

const int N = 30;

int f[32768];
int n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	memset(f, -1, sizeof(f));
	n = read();
	f[0] = 0;
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j < 32768; j++) {
			if (f[j] == -1 && (f[j * 2 % 32768] == i - 1 || f[(j + 1) % 32768] == i - 1)) {
				f[j] = i;
			}
		}
	}
	while (n--) {
		int x = read();
		printf("%d ", f[x]);
	}
	printf("\n");
}