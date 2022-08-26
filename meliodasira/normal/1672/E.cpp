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

int n;

int query(int x) {
	if (!x) return 0;
	printf("? %d\n", x);
	fflush(stdout);
	int ans = read();
	return ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	int l = 1, r = 2000 * 2001, ans = r;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (query(mid) != 1)
			l = mid + 1;
		else
			ans = mid, r = mid - 1;
	}
	int minn = ans;
	for (int i = 2; i <= n; i++) {
		int x = query(ans / i);
		if (x) minn = min(minn, x * (ans / i));
	}
	printf("! %d\n", minn);
	fflush(stdout);
}