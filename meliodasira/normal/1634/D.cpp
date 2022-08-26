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

int a[N];
int n;

int query(int x, int y, int z) {
	printf("? %d %d %d\n", x, y, z);
	fflush(stdout);
	int ans = read();
	return ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int T = read();
	while (T--) {
		n = read();
		for (int i = 3; i <= n; i++) a[i] = query(1, 2, i);
		int ok = 0;
		for (int i = 4; i <= n; i++) {
			if (a[i] != a[3]) {
				ok = 1;
				break;
			}
		}
		int pos;
		if (!ok) {
			int maxn = a[3], ok = 0;
			for (int i = 4; i <= n; i++) {
				if (query(2, 3, i) > maxn) {
					ok = 1;
					printf("! %d %d\n", 3, i);
					fflush(stdout);
					break;
				}
			}
			if (!ok) {
				printf("! %d %d\n", 1, 2);
				fflush(stdout);
			}
			continue;
		} else {
			pos = 3;
			for (int i = 4; i <= n; i++) {
				if (a[i] > a[pos]) {
					pos = i;
				}
			}
		}
		ok = 0;
		int pos2 = (pos == 1 ? 2 : 1), ans = -1;
		for (int i = 1; i <= n; i++) {
			if (i == pos || i == pos2) continue;
			a[i] = query(i, pos, pos2);
			if (ans == -1)
				ans = i;
			else {
				if (a[i] != a[ans]) ok = 1;
				if (a[i] > a[ans]) ans = i;
			}
		}
		if (!ok) {
			printf("! %d %d\n", pos, pos2);
			fflush(stdout);
		} else {
			printf("! %d %d\n", pos, ans);
			fflush(stdout);
		}
	}
}