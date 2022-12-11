// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 1010;

int n, m;
int a[maxn][maxn], b[maxn][maxn];

int main() {

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c = getc();
			while (c != '#' && c != '.')
				c = getc();
			a[i][j] = c == '#' ? 1 : 0;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]
				&& a[i - 1][j] && a[i][j - 1] && a[i - 1][j - 1]
				&& a[i - 1][j + 1] && a[i + 1][j - 1])
				b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1]
				= b[i - 1][j] = b[i][j - 1] = b[i - 1][j - 1]
				= b[i - 1][j + 1] = b[i + 1][j - 1] = 1;
	bool flag = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] && !b[i][j])
				flag = 0;
	if (flag) puts("YES");
	else puts("NO");

	return 0;
}