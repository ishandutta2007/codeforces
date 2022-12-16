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

const int maxn = 1e5 + 10, N = 1e5, mod = 998244353;
typedef mint <mod> mi;
int n, f[maxn];
mi ans[maxn];

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		int a, fre; read(a, fre);
		f[a] = fre;
	}
	for (int i = 1; i <= N; ++i) {
		ll cnt = 0;
		mi s1 = 0, s2 = 0;
		for (int j = i; j <= N; j += i)
			cnt += f[j], s1 += mi(j) * f[j], s2 += mi(j) * j * f[j];
		if (cnt >= 2) {
			mi res = mi(2) ^ (cnt - 2);
			ans[i] += (s1 * s1 - s2) * res + s2 * res * (cnt - 1);
		}
		if (cnt >= 3) {
			mi res = mi(2) ^ (cnt - 3);
			ans[i] += (s1 * s1 - s2) * res * (cnt - 2);
		}
	}
	for (int i = N; i >= 1; --i)
		for (int j = i + i; j <= N; j += i)
			ans[i] -= ans[j];
	write(ans[1].x, '\n');
	return 0;
} //