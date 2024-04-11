// =================================
//   author: memset0
//   date: 2019.03.08 17:01:12
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
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
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 1e3 + 10;
int n, m, tn, ans;
int b[N], F[N], G[N], a[N][N], f[N][N], g[N][N];

void main()  {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) b[j] = a[i][j];
		std::sort(b + 1, b + m + 1);
		F[i] = tn = std::unique(b + 1, b + m + 1) - b - 1;
		for (int j = 1; j <= m; j++) f[i][j] = std::lower_bound(b + 1, b + tn + 1, a[i][j]) - b;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) b[j] = a[j][i];
		std::sort(b + 1, b + n + 1);
		G[i] = tn = std::unique(b + 1, b + n + 1) - b - 1;
		for (int j = 1; j <= n; j++) g[j][i] = std::lower_bound(b + 1, b + tn + 1, a[j][i]) - b;
	}
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= m; j++)
	// 		print(f[i][j], " \n"[j == m]);
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= m; j++)
	// 		print(g[i][j], " \n"[j == m]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			ans = std::max(f[i][j], g[i][j]) + std::max(F[i] - f[i][j], G[j] - g[i][j]);
			print(ans, " \n"[j == m]);
		}
}

} signed main() { return ringo::main(), 0; }