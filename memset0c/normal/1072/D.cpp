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


const int maxN = 2005;

int n, m, max, f[maxN][maxN];
char c[maxN][maxN];
bool used[maxN][maxN];

signed main() {
	read(n), read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { readc(c[i][j]); }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i > 1 && j > 1) f[i][j] = std::min(f[i - 1][j], f[i][j - 1]);
            else if (i > 1) f[i][j] = f[i - 1][j];
            else f[i][j] = f[i][j - 1];
            if (c[i][j] != 'a') { f[i][j]++; }
        }
    }
    if (f[n][n] <= m) {
        for (int i = 1; i < n + n; i++) { putchar('a'); }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == 'a') {
                if (f[i][j] <= m) { max = std::max(max, i + j - 1); }
            } else {
                if (f[i][j] - 1 <= m) { max = std::max(max, i + j - 1); }
            }
        }
    }
    for (int i = 1; i < max; i++) { putchar('a'); }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == 'a') {
                if (f[i][j] <= m && i + j - 1 == max) { used[i][j] = true; }
            } else {
                if (f[i][j] - 1 <= m && i + j - 1 == max) { used[i][j] = true; }
            }
        }
    }
    for (int i = max; i < n + n - 1; i++) {
        char s = '|';
        for (int j = 1; j <= n; j++) {
            if (1 <= i + 1 - j && i + 1 - j <= n && used[i + 1 - j][j]) { s = std::min(s, c[i + 1 - j][j]); }
        }
        putchar(s);
        for (int j = 1; j <= n; j++) {
            if (1 <= i + 1 - j && i + 1 - j <= n && used[i + 1 - j][j] && s == c[i + 1 - j][j]) {
                used[i + 1 - j + 1][j] = true; used[i + 1 - j][j + 1] = true;
            }
        }
    }
    putchar(c[n][n]);
    return 0;
}