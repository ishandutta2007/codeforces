#include <bits/stdc++.h>
#include <cstdlib>
template<class T> inline void read(T& x) {
	x = 0;
	register char c = getchar();
	register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template<class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template<class T> inline void print(T x, char c) { print(x), putchar(c); }
const int N = 1e3 + 10, L = 100, mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int T, n, m, q, a[N][N], f[N][N];
char str[N];
std::queue<std::pair<int, int>> queue;
int main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++) a[i][j] = str[j] == '1';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) f[i][j] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool fl = 0;
			for (int _ = 0; _ < 4; _++) {
				int ni = i + mov[_][0];
				int nj = j + mov[_][1];
				if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
					fl = fl || a[i][j] == a[ni][nj];
				}
			}
			if (fl) { f[i][j] = 0, queue.push(std::make_pair(i, j)); }
		}
	}
	while (queue.size()) {
		int i, j;
		std::tie(i, j) = queue.front();
		queue.pop();
		for (int _ = 0; _ < 4; _++) {
			int ni = i + mov[_][0];
			int nj = j + mov[_][1];
			if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
				if (f[ni][nj] == -1) {
					f[ni][nj] = f[i][j] + 1, queue.push(std::make_pair(ni, nj));
				}
			}
		}
	}
	int x, y;
	long long r;
	while (q--) {
		read(x), read(y), read(r);
		r -= f[x][y];
		if (r < 0 || f[x][y] < 0)
			putchar(a[x][y] + '0');
		else
			putchar('0' + (char)((r & 1) ^ (a[x][y])));
		putchar('\n');
	}
}