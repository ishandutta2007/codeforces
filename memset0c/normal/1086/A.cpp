// =================================
//   author: memset0
//   date: 2018.12.23 21:34:53
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
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

int a, b, c, d, e, f, x, y, ans = 1e9;

inline int dis(int x, int y, int xx, int yy) { return abs(x - xx) + abs(y - yy); }

void move(int x, int y, int xx, int yy) {
	while(x != xx || y != yy) {
		if(x != xx) {
			if(x > xx) x--;
			else x++;
			print(x, ' '); print(y, '\n');
		} else {
			if(y > yy) y--;
			else y++;
			print(x, ' '); print(y, '\n');
		}
	}
}

int main() {
	read(a), read(b), read(c), read(d), read(e), read(f);
	for (int i = std::min(a, c); i <= std::max(a, c); i++) {
		for (int j = std::min(b, d); j <= std::max(b, d); j++) {
			if (dis(a, b, i, j) + dis(c, d, i, j) + dis(e, f, i, j) < ans) {
				ans = dis(a, b, i, j) + dis(c, d, i, j) + dis(e, f, i, j);
				x = i; y = j;
			}
		}
	}
	std::cout << ans + 1 << std::endl;
	move(x, y, a, b); move(x, y, c, d); move(x, y, e, f);
	print(x, ' '); print(y, '\n');
	return 0;
}

} signed main() { return ringo::main(), 0; }