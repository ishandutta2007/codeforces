// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

using namespace std;

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

int n;

void dfs(int n, int v) {
	if (n == 0) return;
	if (n == 3) {
		cout << v << " ";
		cout << v << " ";
		cout << 3 * v << " ";
		return;
	}
	if (n == 2) {
		cout << v << " ";
		cout << v * 2 << " ";
		return;
	}
	if (n == 1) {
		cout << v << " ";
		return;
	}
	for (int i = 1; i <= (n + 1) / 2; i++)
		cout << v << " ";
	dfs(n / 2, v * 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if(n == 2) {
		cout << 1 << " " << 2 << endl;
		return 0;
	}
	if(n == 3) {
		cout << 1 << " " << 1 << " " << 3 << endl;
		return 0;
	}
	dfs(n, 1);
	return 0;
}