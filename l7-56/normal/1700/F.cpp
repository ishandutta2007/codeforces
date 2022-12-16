#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second
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

const int maxn = 2e5 + 10;
int n, a[2][maxn], b[2][maxn], sa, sb;

int main() {
	read(n);
	for (int i : {0, 1})
		for (int j = 1; j <= n; ++j)
			read(a[i][j]), sa += a[i][j];
	for (int i : {0, 1})
		for (int j = 1; j <= n; ++j)
			read(b[i][j]), sb += b[i][j];
	if (sa != sb) return write("-1\n"), 0;
	sa = 0, sb = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += abs(sa) + abs(sb);
		sa += b[0][i] - a[0][i], sb += b[1][i] - a[1][i];
		if ((ll) sa * sb < 0) {
			int x = min(abs(sa), abs(sb)); ans += x;
			if (sa < 0) sa += x, sb -= x;
			else sa -= x, sb += x;
		}
	}
	write(ans, '\n');
	return 0;
}