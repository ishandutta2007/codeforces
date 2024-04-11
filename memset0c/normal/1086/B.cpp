// =================================
//   author: memset0
//   date: 2018.12.23 21:57:03
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

const int N = 1e5 + 10;
int n, u, v, s, cnt;
double ans;
std::vector <int> G[N];

void main() {
	read(n), read(s);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (G[i].size() == 1)
			++cnt;
	ans = (s / (double)cnt) * 2;
	printf("%.12lf\n", ans);
}

} signed main() { return ringo::main(), 0; }