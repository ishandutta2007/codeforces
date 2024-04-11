// =================================
//   author: memset0
//   date: 2019.04.06 19:58:32
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int N = 1e5 + 10;
int n, m, now, ans[N];
ll sum, tl, tr, a[N], b[N], c[N], s[N];

struct query {
	ll l, r, delta, id;
	inline bool operator < (const query &other) const {
		return delta < other.delta;
	}
} p[N];

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(p[i].l), read(p[i].r);
		p[i].delta = p[i].r - p[i].l + 1;
		p[i].id = i;
	}
	std::sort(p + 1, p + m + 1);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];
	std::sort(b + 1, b + n);
	int it = 1;
	for (int i = 1; i <= m; i++) {
		while (b[it] < p[i].delta && it <= n - 1) 
			sum += b[it++];
		ans[p[i].id] = sum + (ll)p[i].delta * (n - it + 1);
	}
	for (int i = 1; i <= m; i++)
		print(ans[i], " \n"[i == m]);
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}