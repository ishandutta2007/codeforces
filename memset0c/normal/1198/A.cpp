// =================================
//   author: memset0
//   date: 2019.07.30 22:34:33
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for (int i = (l), i##ed = (r); i <= i##ed; ++i)
#define for_each(i, a) for (size_t i = 0, i##ed = a.size(); i < i##ed; ++i)
namespace ringo {

template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 4e5 + 10;
int n, m, t, tn, ans, a[N], b[N];

void main() {
	read(n), read(t), t = t * 8 / n, m = 1;
	while (t--) {
		m <<= 1;
		if (m > 1e9) {
			puts("0");
			return;
		}
	}
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) b[i] = a[i];
	tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, (int)(std::upper_bound(a + 1, a + n + 1, a[i] + m - 1) - a - i));
	}
	print(n - ans, '\n');
}

} signed main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}