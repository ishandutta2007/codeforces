// =================================
//   author: memset0
//   date: 2019.01.06 21:44:19
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
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

const int N = 1e5 + 10, M = 110, mod = 998244353;
int n, m, len;
int a[N], f[N][M], s[N], cnt[N][M];

template <class T> inline void sumd(int &a, T b) { a = (a + b) % mod; }
template <class T> inline void decd(int &a, T b) { a = (a - b) % mod; if (a < 0) a += mod; }

void main() {
	read(n), read(m), read(len);
	for (int i = 1; i <= n; i++) read(a[i]);
	s[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cnt[i][j] = cnt[i - 1][j] + (a[i] == -1 || a[i] == j);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (a[i] == -1 || a[i] == j) {
				f[i][j] = s[i - 1];
				if (i - len + 1 >= 1) {
					int pre = i - len;
					if (cnt[i][j] - cnt[pre][j] == len) {
						decd(f[i][j], s[pre] - f[pre][j]);
					}
				}
			}
		for (int j = 0; j <= m; j++) sumd(s[i], f[i][j]);
	}
	print(s[n], '\n');
	// for (int i = 1; i <= n; i++) print(a[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(s[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 0; j <= m; j++)
	// 		print(f[i][j], " \n"[j == m]);
}

} signed main() { return ringo::main(), 0; }