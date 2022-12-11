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

const int maxn = 100010;

int n, m, t;
char s[1000010];
int bit[maxn];
std::map < int, int > cnt;
ll ans;

int main() {
//	freopen("INPUT", "r", stdin);

	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1), t = strlen(s + 1);
		for (int j = 1; j <= t; j++)
			bit[i] ^= 1 << (s[j] - 'a');
	}
	for (int i = 1; i <= n; i++) {
		ans += cnt[bit[i]];
		for (int j = 0; j < 26; j++)
			ans += cnt[bit[i] ^ (1 << j)];
		cnt[bit[i]]++;
	}
	print(ans);

	return 0;
}