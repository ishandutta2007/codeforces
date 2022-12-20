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
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxm = 1e5 + 10, mod = 998244353, inv2 = 499122177;
void FWT_xor(ll *f, int n, int flg) {
	int N = (1 << n);
	for (int len = 2, hlf = 1; len <= N; len <<= 1, hlf <<= 1)
		for (int i = 0; i < N; i += len)
			for (int k = i; k < i + hlf; ++k) {
				ll fk = f[k], fkk = f[k + hlf];
				if (flg == 1) f[k] = (fk + fkk) % mod, f[k + hlf] = (fk - fkk + mod) % mod;
				else f[k] = (fk + fkk) * inv2 % mod, f[k + hlf] = (fk - fkk + mod) * inv2 % mod;
			}
}
int n,m,popcnt[1 << 20],ans;
ll f[1 << 20],g[1 << 20];
char mp[30][maxm];

int main() {
	read(n, m);
	for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
	for (int j = 1; j <= m; ++j) {
		int sta = 0;
		for (int i = 1; i <= n; ++i) sta |= ((mp[i][j] - '0') << (i - 1));
		f[sta]++;
	}
	for (int s = 0; s < (1 << n); ++s) {
		popcnt[s] = popcnt[s >> 1] + (s & 1);
		g[s] = min(popcnt[s], n - popcnt[s]);
	}
	FWT_xor(f, n, 1), FWT_xor(g, n, 1);
	for (int i = 0; i < (1 << n); ++i) f[i] = f[i] * g[i] % mod;
	FWT_xor(f, n, -1);
	ans = INT_MAX;
	for (int i = 0; i < (1 << n); ++i) if (f[i] < ans) ans = f[i];
	write(ans, '\n');
	return 0;
}