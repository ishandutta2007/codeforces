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

const int maxn = 2e5 + 10, maxm = 20, mod = 998244353;
typedef mint <mod> mi;
int n, m, d, q, xl[maxn], xp[maxm];
mi cst[maxm][maxm], dp[maxm];

int main() {
	read(d, n, m);
	for (int i = 1; i <= n; ++i) read(xl[i]);
	for (int i = 1; i <= m; ++i) read(xp[i]);
	sort(xp + 1, xp + m + 1), xp[0] = -1e9, xp[m + 1] = 1e9;
	for (int i = 0; i <= m + 1; ++i)
		for (int j = 0; j <= m + 1; ++j)
			cst[i][j] = 1;
	for (int i = 0; i <= m + 1; ++i)
		for (int j = i + 1; j <= m + 1; ++j)
			for (int k = 1; k <= n; ++k)
				if (xp[i] <= xl[k] && xl[k] <= xp[j]) cst[i][j] *= min({d + 1, xl[k] - xp[i], xp[j] - xl[k]});
	read(q);
	while (q--) {
		int x; read(x);
		dp[0] = 1;
		auto calc = [&] (int i, int j) {
			mi res = cst[i][j];
			if (xp[i] <= x && x <= xp[j]) res *= min({d + 1, x - xp[i], xp[j] - x});
			return res;
		};
		for (int i = 1; i <= m + 1; ++i) {
			dp[i] = calc(0, i);
			for (int j = 1; j < i; ++j) dp[i] -= dp[j] * calc(j, i);
		}
		write(dp[m + 1].x, '\n');
	}
	return 0;
}