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

int t, s, a, b, c;

void main() {
    for (std::cin >> t; t; t--) {
        std::cin >> s >> a >> b >> c;
        std::cout << s / c + 1ll * ((s / c) / a) * b << std::endl;
    }
}

} signed main() { return ringo::main(), 0; }