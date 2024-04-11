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

inline char readc() {
	char ch;
	while (ch = getchar(), ch != 'b' && ch != 'w');
	return ch;
}

int n, c, l = 1, r = 1000000000;

signed main() {
	read(n); --n;
	printf("%d %d\n", 0, 100), fflush(stdout); 
	c = readc();
	for (int i = 1; i <= n; ++i) {
		int mid = (l + r) >> 1;
		printf("%d %d\n", mid, 100), fflush(stdout);
		if (readc() != c) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d %d %d %d\n", l, 0, r, 200);
	return 0;
}