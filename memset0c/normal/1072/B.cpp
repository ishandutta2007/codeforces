// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define int long long
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

const int maxn = 100010;

int n, ok, flag;
int a[maxn], b[maxn], s[maxn];

void solve(int u) {
	if (ok) return;
	s[1] = u;
	flag = 1;
	for (int i = 2; i <= n; i++) {
		s[i] = -1;
		for (int t = 0; t < 4; t++)
			if (((s[i - 1] | t) == a[i - 1]) && ((s[i - 1] & t) == b[i - 1])) {
				s[i] = t;
				break;
			}
		if (!~s[i]) {
			flag = false;
			break;
		}
	}
	if (flag) ok = 1;
}

signed main() {

	read(n);
	for (int i = 1; i < n; i++) read(a[i]);
	for (int i = 1; i < n; i++) read(b[i]);
	solve(0);
	solve(1);
	solve(2);
	solve(3);
	
	if (ok) {
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			print(s[i]);
		putc('\n');
	} else {
		printf("NO\n");
	}

	return 0;
}