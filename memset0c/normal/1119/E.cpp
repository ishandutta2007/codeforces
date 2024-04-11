// =================================
//   author: memset0
//   date: 2019.04.06 20:13:22
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
	x = 0; register char c = getchar(); register bool f = 0;
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

const int N = 3e5 + 10;
int n, a[N], b[N], c[N];
ll l, r, mid, sum, ans, lst;

bool check(ll now) {
	lst = now;
	for (int i = n; i >= 1; i--) {
		b[i] = std::min(lst, (ll)(a[i] >> 1));
		c[i] = a[i] - (b[i] << 1);
		lst -= b[i];
	}
	if (lst) return false;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += c[i] - b[i];
		if (sum < 0) return false;
	}
	return true;
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) sum += a[i];
	l = 1, r = sum / 3;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}