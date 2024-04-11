#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxn = 510, maxm = 250010;
int n, m, f[maxn][maxn];
struct edge {
	int u, v, w;
} e[maxm];

void work() {
	read(n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = i == j ? 0 : 1e9;
	for (int i = 1; i <= m; ++i) {
		read(e[i].u, e[i].v, e[i].w);
		f[e[i].u][e[i].v] = f[e[i].v][e[i].u] = 1;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	ll ans = LLONG_MAX;
	for (int i = 1; i <= m; ++i) {
		int res = min(f[1][e[i].u] + f[e[i].v][n], f[1][e[i].v] + f[e[i].u][n]);
		for (int u = 1; u <= n; ++u)
			res = min(res, min(f[u][e[i].u], f[u][e[i].v]) + 1 + f[1][u] + f[n][u]);
		ans = min(ans, (ll) e[i].w * (res + 1));
	}
	write(ans, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}