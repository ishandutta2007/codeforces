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

const int maxn = 5010;
int n, m, pw2[maxn], f[maxn][maxn], s[maxn][maxn], s2[maxn << 1], g[maxn];
#define inc(x, y) ((x) = ((x) + (y)) % m)

int main() {
	read(n, m);
	pw2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw2[i] = (pw2[i - 1] + pw2[i - 1]) % m;
		for (int j = 1; j < i; ++j) {
			f[i][j] = 1;
			if (i >= 2 * j + 1) inc(f[i][j], s2[i - 2 * j - 1]);
			f[i][j] = (ll) f[i][j] * f[j][j] % m;
		}
		f[i][i] = pw2[i - 1];
		for (int j = 1; j < i; ++j) inc(f[i][i], m - f[i][j]);
		for (int j = 1; j <= n; ++j) s[i][j] = (s[i][j - 1] + f[i][j]) % m;
		for (int j = 1; j <= n; ++j) inc(s2[i + j], s[i][j]);
	}
	write(f[n][n], '\n');
	return 0;
}