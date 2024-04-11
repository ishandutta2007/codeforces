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

const int maxn = 2010, maxm = 2100010;
ll n, m, la, lb, ans;
ll a[maxn], b[maxn];
ll sa[maxn], sb[maxn];
ll ta[maxn], tb[maxn];
ll x;

ll min(ll a, ll b) {
	if (!~a) return b;
	if (!~b) return a;
	return std::min(a, b);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	memset(ta, -1, sizeof(ta));
	memset(tb, -1, sizeof(tb));

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++)
		read(b[i]);
	read(x);
	for (int i = 1; i <= n; i++)
		sa[i] = sa[i - 1] + a[i];
	for (int i = 1; i <= m; i++)
		sb[i] = sb[i - 1] + b[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ta[j - i + 1] = min(ta[j - i + 1], sa[j] - sa[i - 1]);
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++)
			tb[j - i + 1] = min(tb[j - i + 1], sb[j] - sb[i - 1]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (ta[i] * tb[j] <= x)
				ans = std::max(ans, (ll)i * (ll)j);
	print(ans, '\n');

	return 0;
}