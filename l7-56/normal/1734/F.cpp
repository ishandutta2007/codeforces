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

ll n, m, f[70][2][2][2];
ll dfs(ll i, ll up, ll rst, ll j) {
	if (i == -1) return !up && !rst && j;
	if (f[i][up][rst][j] != -1) return f[i][up][rst][j];
	ll res = 0, lim = up ? ((m >> i) & 1) : 1;
	for (ll c = 0; c <= lim; ++c)
		for (ll nr = 0; nr <= 1; ++nr) {
			ll val = ((n >> i) & 1) + c + nr;
			if (val / 2 == rst) res += dfs(i - 1, up && c == lim, nr, c ^ (val & 1) ^ j);
		}
	return f[i][up][rst][j] = res;
}

void work() {
	read(n, m);
	memset(f, -1, sizeof f);
	write(dfs(63, 1, 0, 0), '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}