// =================================
//   author: memset0
//   date: 2019.05.27 00:03:49
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

const int N = 3e5 + 10, L = 19;
int n, m, a[N], tag[L], min[L][L], f[N][L];

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 0; i < L; i++) f[n][i] = ((a[n] >> i) & 1) ? n : n + 1;
	for (int i = 0; i < L; i++) for (int j = 0; j < L; j++) min[i][j] = n + 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < L; j++)
			if ((a[i] >> j) & 1) {
				f[i][j] = i;
				tag[j] = 1;
			} else {
				f[i][j] = n + 1;
				tag[j] = 0;
			}
		for (int j = 0; j < L; j++)
			if (tag[j]) {
				for (int k = 0; k < L; k++)
					f[i][k] = std::min(f[i][k], min[j][k]);
			}
		while (true) {
			int min = n + 1, cho = -1;
			for (int j = 0; j < L; j++)
				if (!tag[j] && f[i][j] < min) {
					min = f[i][j], cho = j;
				}
			if (!~cho) break;
			tag[cho] = 1;
			for (int j = 0; j < L; j++)
				f[i][j] = std::min(f[i][j], f[min][j]);
		}
		for (int j = 0; j < L; j++)
			if ((a[i] >> j) & 1) {
				for (int k = 0; k < L; k++)
					min[j][k] = std::min(min[j][k], f[i][k]);
			}
		// printf(">> %d\n", i);
		// for (int j = 0; j < L; j++)
		// 	for (int k = 0; k < L; k++)
		// 		print(min[i][j][k], " \n"[k == L - 1]);
	}
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 0; j < L; j++)
	// 		print((a[i] >> j) & 1, " \n"[j == L - 1]);
	// for (int i = 1; i <= n; i++) print(f[i], 0, L - 1);
	for (int i = 1, l, r, ans; i <= m; i++) {
		read(l), read(r), ans = 0;
		for (int i = 0; i < L && !ans; i++)
			if ((a[r] >> i) & 1) {
				ans |= f[l][i] <= r;
			}
		puts(ans ? "Shi" : "Fou");
	}
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}