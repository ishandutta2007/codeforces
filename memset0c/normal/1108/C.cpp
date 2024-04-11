// =================================
//   author: memset0
//   date: 2019.01.27 10:38:07
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

int n, ans, now, ansa, ansb, ansc;
int map[300], cnt[3][3];

void solve(int a, int b, int c) {
	now = n - cnt[0][a] - cnt[1][b] - cnt[2][c];
	if (now < ans) ans = now, ansa = a, ansb = b, ansc = c;
}

void main() {
	map['R'] = 0, map['G'] = 1, map['B'] = 2;
	read(n);
	for (int i = 1; i <= n; i++) cnt[i % 3][map[getchar()]]++;
	ans = n;
	solve(0, 1, 2);
	solve(0, 2, 1);
	solve(1, 0, 2);
	solve(1, 2, 0);
	solve(2, 0, 1);
	solve(2, 1, 0);
	print(ans, '\n');
	map[0] = ansa ? (ansa == 1 ? 'G' : 'B') : 'R';
	map[1] = ansb ? (ansb == 1 ? 'G' : 'B') : 'R';
	map[2] = ansc ? (ansc == 1 ? 'G' : 'B') : 'R';
	for (int i = 1; i <= n; i++) putchar(map[i % 3]);
	putchar('\n');
}

} signed main() { return ringo::main(), 0; }