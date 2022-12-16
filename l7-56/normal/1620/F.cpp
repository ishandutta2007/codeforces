// LUOGU_RID: 92727401
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
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

const int maxn = 1e6 + 10, inf = 1e9;
#define chkmn(x, y) ((x) = (x) < (y) ? (x) : (y))
int n, p[maxn][2], f[maxn][2], a[maxn];
void work() {
	f[0][0] = f[0][1] = p[0][0] = p[0][1] = -inf;
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(p[i][0]), p[i][1] = -p[i][0];
		f[i][0] = f[i][1] = inf;
		for (int a : {0, 1})
			for (int b : {0, 1}) {
				if (p[i - 1][a] < p[i][b]) chkmn(f[i][b], f[i - 1][a]);
				if (f[i - 1][a] < p[i][b]) chkmn(f[i][b], p[i - 1][a]);
			}
	}
	if (min(f[n][0], f[n][1]) == inf) return write("NO\n");
	write("YES\n");
	int i = n, j = f[n][0] < f[n][1] ? 0 : 1;
	while (i) {
		a[i] = p[i][j];
		for (int a : {0, 1}) {
			if (p[i - 1][a] < p[i][j] && f[i][j] == f[i - 1][a]) { --i, j = a; break; }
			if (f[i - 1][a] < p[i][j] && f[i][j] == p[i - 1][a]) { --i, j = a; break; }
		}
	}
	for (int i = 1; i <= n; ++i) write(a[i], " \n"[i == n]);
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}