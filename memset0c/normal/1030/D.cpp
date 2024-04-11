// =================================
//   author: memset0
//   date: 2018.12.24 22:36:52
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
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
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

ll n, m, k;

void main() {
	read(n), read(m), read(k);
	if (2 * n * m % k) puts("NO");
	else {
		ll _n = n, _m = m, t = 2;
		if (k % t == 0) k /= t, t = 1;
		for (ll i = 2; i * i <= k; i++)
			while (k % i == 0) {
				if (n % i == 0) n /= i;
				else m /= i;
				k /= i;
			}
		if (n % k == 0) n /= k, k /= k;
		if (m % k == 0) m /= k, k /= k;
		if (n * t <= _n) n *= t;
		else m *= t;
		printf("YES\n0 0\n%lld 0\n0 %lld\n", n, m);
		// printf("YES\n0 0\n%I64d 0\n0 %I64d\n", n, m);
	}
}

} signed main() { return ringo::main(), 0; }

//976562438476562.5