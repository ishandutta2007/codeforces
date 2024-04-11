// =================================
//   author: memset0
//   date: 2019.04.29 22:55:30
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

const int N = 1e5 + 10, M = 255;
int n, m, lst[26], p[N][26], f[M][M][M];
std::vector<char> a[4];
char s[N];

inline void move(int i, int j, int k) {
	// printf("move %d %d %d\n", i, j, k);
	f[i][j][k] = n + 1;
	if (i) {
		f[i][j][k] = std::min(f[i][j][k], p[f[i - 1][j][k]][a[1][i - 1] - 'a']);
	}
	if (j) {
		f[i][j][k] = std::min(f[i][j][k], p[f[i][j - 1][k]][a[2][j - 1] - 'a']);
	}
	if (k) {
		f[i][j][k] = std::min(f[i][j][k], p[f[i][j][k - 1]][a[3][k - 1] - 'a']);
	}
}

void main() {
	read(n), read(m), scanf("%s", s + 1);

	for (int i = 0; i < 26; i++) lst[i] = n + 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 26; j++) p[i][j] = lst[j];
		lst[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		p[0][i] = lst[i];
		p[n + 1][i] = n + 1;
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("[%d %d %d %d]\n", p[i][0], p[i][1], p[i][2], p[i][3]);
	// }

	f[0][0][0] = 0;
	for (int i = 1, x, c, opt; i <= m; i++) {
		while (opt = getchar(), opt != '+' && opt != '-');
		if (opt == '+') {
			read(x), c = getchar();
			a[x].push_back(c);
			if (x == 1) {
				int i = a[1].size();
				for (int j = 0; j <= a[2].size(); j++)
					for (int k = 0; k <= a[3].size(); k++)
						move(i, j, k);
			} else if (x == 2) {
				int j = a[2].size();
				for (int i = 0; i <= a[1].size(); i++)
					for (int k = 0; k <= a[3].size(); k++)
						move(i, j, k);
			} else {
				int k = a[3].size();
				for (int i = 0; i <= a[1].size(); i++)
					for (int j = 0; j <= a[2].size(); j++)
						move(i, j, k);
			}
		} else {
			read(x);
			a[x].pop_back();
		}
		// printf(">> %d : %c\n", i, opt);
		// for (int i = 0; i <= a[1].size(); i++) {
		// 	for (int j = 0; j <= a[2].size(); j++)
		// 		for (int k = 0; k <= a[3].size(); k++)
		// 			print(f[i][j][k], " \n"[k == a[3].size()]);
		// 	puts("");
		// }
		puts(f[a[1].size()][a[2].size()][a[3].size()] <= n ? "YES" : "NO");
	}
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}