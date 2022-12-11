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

//fadjfksdjf idjsifjaewiofjadsfdsf

int t, n, m, a, b, c, d, e, f, g, h, A, B, C, D;

typedef std::pair < int, int > pair;
pair ans, dec1, dec2;

pair operator + (const pair &a, const pair &b) {
	return std::make_pair(a.first + b.first, a.second + b.second);
}
pair operator - (const pair &a, const pair &b) {
	return std::make_pair(a.first - b.first, a.second - b.second);
}

int get(int a, int b, int c, int d) {
	if (a > c || b > d) return 0;
	return (c - a + 1) * (d - b + 1);
}

pair calc(int a, int b, int c, int d) {
	if (a > c || b > d) return std::make_pair(0, 0);
	int full = (c - a + 1) * (d - b + 1);
	if (full & 1) {
		if ((a + b) & 1) return std::make_pair(full >> 1, (full + 1) >> 1);
		else return std::make_pair((full + 1) >> 1, full >> 1);
	} else return std::make_pair(full >> 1, full >> 1);
}

void main() {
	read(t);
	//dfamfdsjkfasdmlfjkmdskfjadjlk
	while (t--) {
		read(n), read(m);
		read(a), read(b), read(c), read(d);
		read(e), read(f), read(g), read(h);
		A = std::max(a, e), B = std::max(b, f);
		C = std::min(c, g), D = std::min(d, h);
		ans.first = ans.second = 0;
		ans = calc(1, 1, n, m);
		ans = ans - calc(a, b, c, d);
		ans = ans - calc(e, f, g, h);
		ans = ans + calc(A, B, C, D);
		ans = ans + std::make_pair(get(a, b, c, d), 0);
		ans = ans + std::make_pair(0, get(e, f, g, h));
		ans = ans - std::make_pair(get(A, B, C, D), 0);
		print(ans.first), putc(' ');
		print(ans.second), putc('\n');
	}
}

//gsdgdfgdsgdfg
} signed main() { return ringo::main(), 0; }

//dafj kdjskfjadkslfjdksjfakldsjfkldsf