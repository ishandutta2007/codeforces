// LUOGU_RID: 93400076
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

const int maxn = 1e7 + 10, N = 1e7, mod = 1e9 + 7, inv2 = 5e8 + 4;
typedef mint <mod> mi;
int n, m;
mi fac[maxn], ifac[maxn], pw2[maxn];
mi C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fac[n] * ifac[m] * ifac[n - m];
}
void prework() {
	fac[0] = 1;
	for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i;
	ifac[N] = 1 / fac[N];
	for (int i = N; i >= 1; --i) ifac[i - 1] = ifac[i] * i;
	pw2[0] = 1;
	for (int i = 1; i <= N; ++i) pw2[i] = pw2[i - 1] * 2;
}

void work() {
	read(n, m);
	mi ans = 0;
	for (int i = 0; i <= n && i <= m; ++i)
		ans += C(n, i) * C(m, i) * pw2[n + m - i - 1] * (mi(n + m - i + 1) * inv2 + 1 + i);
	write(ans.x, '\n');
}

int main() {
	prework();
	int T; read(T);
	while (T--) work();
	return 0;
}