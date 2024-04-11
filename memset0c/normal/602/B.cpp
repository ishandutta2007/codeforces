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

const int N = 1e5 + 10;
int n, i, j, u, ans, now, a[N], cnt[N];

void main() {
	for (read(n), i = j = 1; i <= n; i++) {
		read(a[i]), now += !cnt[a[i]]++;
		while (now > 2) now -= !--cnt[a[j++]];
		ans = std::max(ans, i - j + 1);
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }