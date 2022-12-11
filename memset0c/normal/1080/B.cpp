#include <bits/stdc++.h>
#define il inline
#define rg register
#define int long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

int n, l, r;

il int query(int x) {
    if (x & 1) return -(x / 2 + 1);
	else return x / 2;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
		read(l), read(r);
        std::cout << query(r) - query(l - 1) << std::endl;
    }
    return 0;
}

//afdjfdsfasfasfasfddf
} signed main() { return ringo::main(), 0; }