// luogu-judger-enable-o2
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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 16777216;
const int p = 1e9 + 7;

#define lowbit(x) ((x)&(-(x)))

int n, m, t, b1, b2, dis;
int a[25], f[maxn], lg2[1 << 24];

int main() {

	read(n);
	for (register int i = 1; i <= n; i++)
		read(a[i]);
	read(m);
	if (m) read(b1);
	if (m & 2) read(b2);
	
	f[0] = 1;
	for (register int i = 1; i <= n; i++)
		lg2[1 << (i - 1)] = i;
	for (register int x = 1, y, t, dis; x < (1 << n); x++) {
		y = x, dis = 0;
		while (y) {
			t = lowbit(y);
			dis += a[lg2[t]];
			f[x] += f[x ^ t];
			if (f[x] > p) f[x] -= p;
			y -= t;
		}
		if (m && dis == b1) f[x] = 0;
		if (m & 2 && dis == b2) f[x] = 0;
	}
	print(f[(1 << n) - 1]);

	return 0;
}