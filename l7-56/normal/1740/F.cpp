// LUOGU_RID: 92442263
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
};

const int maxn = 2010, mod = 998244353;
typedef mint <mod> mi;
int n, a[maxn], cnt[maxn], lim[maxn];
mi f[maxn][maxn], g[maxn][maxn];
void clr(mi f[maxn][maxn], int i) {
	int mxk = n / max(i, 1) + 2;
	for (int j = 0; j <= lim[i]; ++j)
		for (int k = 1; k <= mxk; ++k)
			f[j][k] = 0;
}

void calc(int i) {
	int mxk = n / max(i, 1) + 2;
	for (int j = 0; j <= lim[i]; ++j)
		for (int k = mxk; k >= 1; --k)
			g[j][k] = g[j][k + 1] + f[j][k];
}

void trs(int i) {
	int mxk = n / max(i, 1) + 2;
	for (int j = 0; j <= lim[i]; ++j)
		for (int k = 1; k <= mxk && k <= j; ++k)
			f[j][k] = g[j - k][k];
}

mi ans;
void update(int i) {
	int mxk = n / max(i, 1) + 2;
	for (int k = 1; k <= mxk; ++k) ans += f[n][k];
}

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]), lim[++cnt[a[i]]]++;
	for (int i = 1; i <= n; ++i) lim[i] += lim[i - 1];
	for (int i = 1; i <= lim[1]; ++i) f[i][i] = 1;
	calc(1), update(1);
	for (int i = 2; i <= n; ++i)
		clr(f, i - 1), trs(i), clr(g, i - 1), calc(i), update(i);
	write(ans.x, '\n');
	return 0;
}