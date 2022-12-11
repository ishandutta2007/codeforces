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
inline void read1d(int &x) {
    while (x = getc(), !isdigit(x));
    x -= '0';
}

const int maxn = 1000010;
int n, k, a[maxn];

void solve() {
    for (int i = 1; i <= n && k; i++) {
        if (i >= 3) {
            if (a[i] == 7 && a[i - 1] == 4 && a[i - 2] == 4 && (i & 1)) {
                if (k & 1) a[i - 1] = 7;
//				printf(">>> %d %d\n", i, k);
                k = 0;
            }
            if (a[i] == 7 && a[i - 1] == 7 && a[i - 2] == 4 && !(i & 1)) {
                if (k & 1) a[i - 1] = 4;
//				printf(">>> %d %d\n", i, k);
                k = 0;
            }
        }
        if (i >= 2 && k) {
            if (a[i] == 7 && a[i - 1] == 4) {
                if (i & 1) {
                    a[i - 1] = 7;
                } else {
                    a[i] = 4;
                }
//				printf(">>> %d %d\n", i, k);
                k--;
            }
        }
    }
}

int main() {
//	freopen("trans.in", "r", stdin);
//	freopen("trans.out", "w", stdout);
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++)
            read1d(a[i]);
        solve();
        for (int i = 1; i <= n; i++)
            putc(a[i] + '0');
        putc('\n');
    }
    return 0;
}