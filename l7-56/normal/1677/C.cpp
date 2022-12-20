#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn], pos[maxn], vis[maxn];
void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]), pos[a[i]] = i;
	for (int i = 1; i <= n; ++i) read(b[i]), vis[i] = 0;
	int totlen = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		int j = i, len = 0;
		do {
			vis[j] = 1;
			j = pos[b[j]];
			++len;
		} while (j != i);
		totlen += len / 2;
	}
	ll ans = 0;
	for (int i = 1; i <= totlen; ++i) ans += 2 * (n - i * 2 + 1);
	write(ans, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}