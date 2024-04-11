#include <bits/stdc++.h> 
#define int long long
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
  
const int inf = 1e15;
int t, n, x, y, d, ans;

int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return std::min(a, b);
}

void main() {
	read(t);
	while (t--) {
		read(n), read(x), read(y), read(d);
		ans = -1;
		if (!(abs(y - x) % d)) ans = min(ans, abs(y - x) / d);
		if (!((y - 1) % d)) ans = min(ans, (y - 1) / d + (x - 1 + d - 1) / d);
		if (!((n - y) % d)) ans = min(ans, (n - y) / d + (n - x + d - 1) / d);
		print(ans, '\n');
	}
}

} signed main() { return ringo::main(), 0; }