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

		mint & operator ++ () { return *this += 1; }
		const mint operator ++ (int) { mint t = *this; *this += 1; return t; }
		mint & operator -- () { return *this -= 1; }
		const mint operator -- (int) { mint t = *this; *this -= 1; return t; }

		friend bool operator == (mint a, mint b) { return a.x == b.x; }
		friend bool operator != (mint a, mint b) { return a.x != b.x; }
};

const int maxn = 2e5 + 10, n = 17, N = 1 << 17, mod = 1e9 + 7;
typedef mint <mod> mi;
const mi inv2 = mi(2) ^ (mod - 2);

void FWT_or(mi *f, int flg) {
	for (int len = 2, hlf = 1; len <= N; len <<= 1, hlf <<= 1)
		for (int i = 0; i < N; i += len)
			for (int k = i; k < i + hlf; ++k)
				f[k + hlf] += flg * f[k];
}
void FWT_and(mi *f, int flg) {
	for (int len = 2, hlf = 1; len <= N; len <<= 1, hlf <<= 1)
		for (int i = 0; i < N; i += len)
			for (int k = i; k < i + hlf; ++k)
				f[k] += flg * f[k + hlf];
}
void FWT_xor(mi *f, int flg) {
	for (int len = 2, hlf = 1; len <= N; len <<= 1, hlf <<= 1)
		for (int i = 0; i < N; i += len)
			for (int k = i; k < i + hlf; ++k) {
				mi fk = f[k], fkk = f[k + hlf];
				if (flg == 1) f[k] = fk + fkk, f[k + hlf] = fk - fkk;
				else f[k] = (fk + fkk) * inv2, f[k + hlf] = (fk - fkk) * inv2;
			}
}
int cnt[maxn],popcnt[maxn];
mi fib[maxn],f[maxn],a[maxn],b[maxn],c[maxn],t[20][maxn];

int main() {
	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i < N; ++i) fib[i] = fib[i - 1] + fib[i - 2];
	for (int i = 0; i < N; ++i) popcnt[i] = popcnt[i >> 1] + (i & 1);
	int nn; read(nn);
	for (int x; nn--; ) read(x), cnt[x]++;

	for (int i = 0; i < N; ++i) t[popcnt[i]][i] = cnt[i];
	for (int i = 0; i <= n; ++i) {
		FWT_or(t[i], 1);
		for (int j = 0; j < N; ++j) f[j] = 0;
			for (int j = 0; j <= i; ++j)
				for (int k = 0; k < N; ++k)
					f[k] += t[j][k] * t[i - j][k];
		FWT_or(f, -1);
		for (int j = 0; j < N; ++j)
			if (popcnt[j] == i) a[j] += f[j] * fib[j];
	}

	for (int i = 0; i < N; ++i) b[i] = cnt[i] * fib[i];

	for (int i = 0; i < N; ++i) f[i] = cnt[i];
	FWT_xor(f, 1);
	for (int i = 0; i < N; ++i) f[i] *= f[i];
	FWT_xor(f, -1);
	for (int i = 0; i < N; ++i) c[i] = f[i] * fib[i];

	FWT_and(a, 1), FWT_and(b, 1), FWT_and(c, 1);
	for (int i = 0; i < N; ++i) f[i] = a[i] * b[i] * c[i];
	FWT_and(f, -1);
	mi ans = 0;
	for (int i = 0; i < n; ++i) ans += f[1 << i];
	write(ans.x, '\n');
	return 0;
}