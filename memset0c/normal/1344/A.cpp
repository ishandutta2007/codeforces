#include <bits/stdc++.h>
template<class T> inline void read(T& x) {
	x = 0;
	register char c = getchar();
	register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template<class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template<class T> inline void print(T x, char c) { print(x), putchar(c); }
const int N = 4e5 + 10;
int T, n, a[N];
bool vis[N];
void solve() {
	read(n);
	memset(vis, 0, sizeof(bool[n]));
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		if (vis[((a[i] + i) % n + n) % n]) {
			puts("No");
			return;
		}
		vis[((a[i] + i) % n + n) % n] = true;
	}
	puts("Yes");
}
int main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	read(T);
	while (T--) solve();
}