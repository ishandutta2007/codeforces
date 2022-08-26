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

const int N = 1e5 + 5;

int a[N], b[N];
int T, n, q;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) a[i] = read();
		int len = n, cnt = 0;
		rep(i, 1, n - 1) {
			if (len == 0) break;
			int nlen = 0, ncnt = cnt;
			rep(j, 1, len - 1) {
				if (a[j + 1] == a[j]) {
					++ncnt;
				} else {
					b[++nlen] = a[j + 1] - a[j];
				}
			}
			if (cnt) {
				b[++nlen] = a[1], --ncnt;
			}
			sort(b + 1, b + nlen + 1);
			len = nlen;
			cnt = ncnt;
			rep(j, 1, len) a[j] = b[j];
		}
		if (len)
			printf("%d\n", a[1]);
		else
			printf("0\n");
	}
}