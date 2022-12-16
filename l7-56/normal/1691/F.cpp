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
template <int mod>
class mint {
	public:
		int x;
		mint() : x(0) {}
		mint(int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		friend mint operator + (mint a, mint b) { return (a.x += b.x) >= mod ? a.x -= mod : 0, a; }
		friend mint operator - (mint a, mint b) { return (a.x -= b.x) < 0 ? a.x += mod : 0, a; }
		friend mint operator * (mint a, mint b) { return a.x = 1ll * a.x * b.x % mod, a; }
		template <typename __Tp> friend mint operator ^ (mint a, __Tp p) {
			mint ans = 1;
			while (p) {
				if (p & 1) ans = ans * a;
				a = a * a, p >>= 1;
			}
			return ans;
		}
		friend mint operator / (mint a, mint b) { return a * (b ^ (mod - 2)); }
		friend mint & operator += (mint &a, mint b) { return a = a + b; }
		friend mint & operator -= (mint &a, mint b) { return a = a - b; }
		friend mint & operator *= (mint &a, mint b) { return a = a * b; }
		friend mint & operator /= (mint &a, mint b) { return a = a / b; }
		friend mint & operator ^= (mint &a, int b) { return a = a ^ b; }

		mint & operator ++ () { return *this += 1; }
		const mint operator ++ (int) { mint t = *this; *this += 1; return t; }
		mint & operator -- () { return *this -= 1; }
		const mint operator -- (int) { mint t = *this; *this -= 1; return t; }

		friend bool operator == (mint a, mint b) { return a.x == b.x; }
		friend bool operator != (mint a, mint b) { return a.x != b.x; }
};

const int maxn = 2e5 + 10, mod = 1e9 + 7;
typedef mint <mod> mi;
int n, k, siz[maxn];
mi f[maxn], g[maxn], ans, fac[maxn], ifac[maxn], a[maxn];
vector <int> e[maxn];

mi C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fac[n] * ifac[m] * ifac[n - m];
}

void dfs1(int u, int pre) {
	siz[u] = 1, a[u] = f[u] = 0;
	for (int v : e[u]) if (v != pre)
		dfs1(v, u), f[u] += f[v], siz[u] += siz[v], a[u] -= C(siz[v], k);
	a[u] += C(siz[u], k);
	f[u] += a[u] * siz[u];
}

void dfs2(int u, int pre) {
	mi sum = 0, ra = a[u] - C(siz[u], k) - C(n - siz[u], k);
	for (int v : e[u]) if (v != pre) sum += f[v];
	for (int v : e[u]) if (v != pre) {
		g[v] = g[u] + sum - f[v] +
			(n - siz[v]) * (ra + C(siz[v], k) + C(n - siz[v], k));
		dfs2(v, u);
	}
	ans += sum + g[u] + n * (ra + C(n, k));
}

int main() {
	read(n, k);
	for (int i = 1; i < n; ++i) {
		int x, y; read(x, y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n + 5; ++i) fac[i] = fac[i - 1] * i, ifac[i] = 1 / fac[i];

	dfs1(1, 0), dfs2(1, 0);
	write(ans.x, '\n');
	return 0;
}