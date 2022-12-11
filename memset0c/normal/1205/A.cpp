// =================================
//   author: memset0
//   date: 2019.08.18 21:45:12
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
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
template <class T> inline void print(T a, int l, int r) { for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]); }
 
const int N = 1e5 + 10;
int n, a[N << 1];
ll m;
 
void main() {
	read(n), m = ((ll)n * (n + 1) / 2) / 2;
	if (n & 1) {
		a[1] = 1;
		for (int i = 2; i <= n; i++) {
			if ((i & 1) ^ 1) {
				a[i] = i << 1;
			} else {
				a[i] = (i - 1) << 1 | 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i & 1) {
				a[i + n] = a[i] + 1;
			} else {
				a[i + n] = a[i] - 1;
			}
		}
		puts("YES");
		print(a, 1, n << 1);
	} else {
		puts("NO");
	}
}
 
} signed main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	ringo::main();
	std::cerr << "clock: " << clock() / double(CLOCKS_PER_SEC) << std::endl;
}