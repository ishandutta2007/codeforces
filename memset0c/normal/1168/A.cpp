// =================================
//   author: memset0
//   date: 2019.05.26 23:34:07
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 3e5 + 10;
int n, m, ans, l, r, mid, a[N];

bool check(int x) {
	// printf(">> check %d\n", x);
	int min = (a[1] + x < m ? a[1] : 0);
	for (int i = 2; i <= n; i++) {
		// printf("> %d %d %d\n", i, a[i], min);
		if (a[i] + x < m) {
			if (min > a[i] + x) return false;
			min = std::max(min, a[i]);
		} else {
			if (min >= a[i]) {

			} else if (min <= (a[i] + x) % m) {

			} else {
				min = std::max(min, a[i]);
			}
		}
	}
	return true;
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	ans = m, l = 0, r = m - 1;
	while (l <= r) {
		if (check(mid = (l + r) >> 1)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}