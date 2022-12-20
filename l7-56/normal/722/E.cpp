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

const int maxn = 1e6 + 10, maxk = 2010, T = 22, mod = 1e9 + 7;
#define inc(x, y) (((((x) += (y)) %= mod) += mod) %= mod)
int qpow(int a, int p) {
	int ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod, p >>= 1;
	}
	return ans;
}
int n,m,k,s,f[maxk][30],fact[maxn],inv[maxn],ans;
int C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return 1ll * fact[n] * inv[m] % mod * inv[n - m] % mod;
}
struct node {
	int x, y;
	friend bool operator < (node p, node q) { return p.x == q.x ? p.y < q.y : p.x < q.x; }
}a[maxn];

int main() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= 1000000; ++i) fact[i] = 1ll * fact[i - 1] * i % mod, inv[i] = qpow(fact[i], mod - 2);
	read(n, m, k, s);
	for (int i = 1; i <= k; ++i) read(a[i].x, a[i].y);
	a[++k] = {1, 1}, a[++k] = {n, m}, s <<= 2;
	sort(a + 1, a + k + 1);
	f[1][1] = 1;
	for (int i = 2; i <= k; ++i) {
		for (int j = 1; j <= T; ++j) {
			f[i][j] = C(a[i].x + a[i].y - 2, a[i].x - 1);
			for (int p = 1; p < i; ++p)
				if (a[p].x <= a[i].x && a[p].y <= a[i].y)
					inc(f[i][j], -1ll * f[p][j] * C(a[i].x - a[p].x + a[i].y - a[p].y, a[i].x - a[p].x) % mod);
		}
		for (int j = T; j > 1; --j) inc(f[i][j], -f[i][j - 1]);
	}
	int sum = 0;
	for (int j = 1; j <= T; ++j) {
		s = (s + 1) >> 1;
		inc(ans, 1ll * f[k][j] * s % mod);
		inc(sum, f[k][j]);
	}
	inc(ans, (C(n + m - 2, n - 1) - sum + mod) % mod);
	ans = 1ll * ans * qpow(C(n + m - 2, n - 1), mod - 2) % mod;
	write(ans, '\n');
	return 0;
}