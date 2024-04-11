// =================================
//   author: memset0
//   date: 2019.05.06 17:11:29
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
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

#define gcd std::__gcd
#define lcm(a, b) ((ll)(a) * (b) / gcd(a, b))

int a, b, c;
ll max, ans, now;

inline void solve(int p) {
	int k = p - a % p;
	now = lcm(a + k, b + k);
	if (now < max) {
		// printf("%lld %d | %d %d\n", now, k, a + k, b + k);
		max = now;
		ans = k;
	}
}

void main() {
	read(a), read(b);
	c = std::abs(a - b);
	max = lcm(a, b), ans = 0;
	for (int i = 1; i * i <= c; i++)
		if (c % i == 0) {
			solve(i);
			solve(c / i);
		}
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}