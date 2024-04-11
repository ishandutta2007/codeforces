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

const int maxn = 1e6 + 10;
int n,sx,sy,ex,ey,ans;
pii t[maxn];
vector <pii> b[maxn];
bitset <maxn> c;

int main() {
	read(sx, ey, ex, sy, n);
	for (int i = 1; i <= n; ++i) read(t[i].fir, t[i].sec);
	for (int i = 1; i <= n; ++i) {
		pii p = t[i], q = t[i % n + 1];
		if (p.fir == q.fir) {
			int l = max(sy, min(p.sec, q.sec)), r = min(ey, max(p.sec, q.sec)), flg = p.sec > q.sec;
			if (l < r)
				b[p.fir].push_back(flg ? make_pair(r, l) : make_pair(l, r));
		}
	}
	for (int x = 0; x < ex; ++x) {
		for (pii p : b[x]) {
			int u = p.fir, v = p.sec;
			// printf("(%d, %d, %d)\n", x, u, v);
			if (x > sx && u > v && c[u] == c[v]) ans += c[u] ? -1 : 1;
			c[u] = !c[u], c[v] = !c[v];
		}
		if (x == sx) {
			for (int y = 0; y <= 15000; ++y) ans += c[y];
			ans >>= 1;
		}
	}
	write(ans, '\n');
	return 0;
}