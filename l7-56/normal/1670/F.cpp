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

const ll maxn = 3010, mod = 1e9 + 7, B = 60;
typedef mint <mod> mi;
ll n;
mi f[maxn], g[maxn], fact[maxn], invf[maxn];
mi C(ll n, ll m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fact[n] * invf[m] * invf[n - m];
}

mi calc(ll lim, ll z) {
	if (lim < z) return 0;
	for (ll j = 0; j <= n; ++j) f[j] = 0;
	f[0] = 1;
	for (ll bit = B; bit >= 0; --bit) {
		for (ll j = 0; j <= n; ++j) g[j] = f[j], f[j] = 0;
		for (ll j = 0; j <= n; ++j) if (g[j].x) {
			ll nj = (j << 1) | ((lim >> bit) & 1);
			for (ll k = (z >> bit) & 1; k <= nj && k <= n; k += 2)
				f[min(nj - k, n)] += g[j] * C(n, k);
		}
	}
	mi ans = 0;
	for (ll j = 0; j <= n; ++j) ans += f[j];
	return ans;
}

int main() {
	ll l, r, z;
	scanf("%lld%lld%lld%lld", &n, &l, &r, &z);
	fact[0] = invf[0] = 1;
	for (ll i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i, invf[i] = 1 / fact[i];
	printf("%d\n", (calc(r, z) - calc(l - 1, z)).x);
	return 0;
}