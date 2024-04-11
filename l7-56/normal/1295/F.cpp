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

const int maxn = 110, mod = 998244353;
typedef mint <mod> mi;
int n, m, X[maxn];
pii a[maxn];
mi f[maxn][maxn];

mi C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	mi res = 1;
	for (int i = 1; i <= m; ++i) res *= n - i + 1, res /= i;
	return res;
}

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i].fir, a[i].sec), X[++m] = a[i].fir, X[++m] = a[i].sec + 1;
	reverse(a + 1, a + n + 1);
	sort(X + 1, X + m + 1), m = unique(X + 1, X + m + 1) - X - 1;
	for (int j = 0; j < m; ++j) f[0][j] = 1;
	mi mul = 1;
	for (int i = 1; i <= n; ++i) {
		mul /= a[i].sec - a[i].fir + 1;
		for (int j = 1; j < m; ++j) {
			f[i][j] = f[i][j - 1];
			for (int k = i; k >= 1; --k) {
				if (X[j] < a[k].fir || X[j] > a[k].sec) break;
				f[i][j] += f[k - 1][j - 1] * C(X[j + 1] - X[j] + i - k, i - k + 1);
			}
		}
	}
	mul *= f[n][m - 1];
	write(mul.x, '\n');
	return 0;
}