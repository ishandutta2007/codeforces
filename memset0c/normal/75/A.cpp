// =================================
//   author: memset0
//   date: 2018.12.07 23:02:21
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

int x, y, z;

int f(int x) {
	// printf("%d =>", x);
	std::vector < int > a;
	while (x) {
		a.push_back(x % 10);
		x /= 10;
	}
	std::reverse(a.begin(), a.end());
	for (auto u : a)
		if (u)
			x = x * 10 + u;
	// printf(" %d\n", x);
	return x;
}

void main() {
	read(x), read(y), z = x + y;
	puts(f(x) + f(y) == f(z) ? "YES" : "NO");
}

} signed main() { return ringo::main(), 0; }