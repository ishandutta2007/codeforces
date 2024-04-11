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

ll n, m;

void main() {
    std::cin >> n >> m;
    std::cout << std::max(0ll, n - m * 2) << " ";
    for (int i = n; ~i; i--) {
        if (1ll * (n - i) * (n - i - 1) / 2 >= m) {
			std::cout << i << std::endl;
			break;
		}
    }
}

} signed main() { return ringo::main(), 0; }