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

const int maxn = 2010;

int n, m;
double p, ans, f[maxn][maxn];

int main() {
	// freopen("1.in", "r", stdin);

	scanf("%d%lf%d\n", &n, &p, &m);
	f[0][0] = 1;
	for (int i = 0; i <= m; i++) {
		f[i + 1][n] += f[i][n];
		for (int j = 0; j <= std::min(n - 1, i); j++) {
			f[i + 1][j] += f[i][j] * (1 - p);
			f[i + 1][j + 1] += f[i][j] * p;
		}
	}
	// for (int i = 1; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++)
	// 		printf("%2.2lf ", f[i][j]);
	// 	putc('\n');
	// }
	for (int i = 0; i <= std::min(n, m); i++)
		ans += f[m][i] * i;
	printf("%.8lf\n", ans);

	return 0;
}