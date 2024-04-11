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

const int maxn = 1e5 + 10;
int fa[maxn], siz[maxn], n, m, k, mod;
class mi {
	public:
		int x;
		mi() : x(0) {}
		mi(int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mi(long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mi(unsigned int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mi(unsigned long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		friend mi operator + (mi a, mi b) { return (a.x += b.x) >= mod ? a.x -= mod : 0, a; }
		friend mi operator - (mi a, mi b) { return (a.x -= b.x) < 0 ? a.x += mod : 0, a; }
		friend mi operator * (mi a, mi b) { return a.x = 1ll * a.x * b.x % mod, a; }
		template <typename __Tp> friend mi operator ^ (mi a, __Tp p) {
			mi ans = 1;
			while (p) {
				if (p & 1) ans = ans * a;
				a = a * a, p >>= 1;
			}
			return ans;
		}
		friend mi operator / (mi a, mi b) { return a * (b ^ (mod - 2)); }
		friend mi & operator += (mi &a, mi b) { return a = a + b; }
		friend mi & operator -= (mi &a, mi b) { return a = a - b; }
		friend mi & operator *= (mi &a, mi b) { return a = a * b; }
		friend mi & operator /= (mi &a, mi b) { return a = a / b; }
		friend mi & operator ^= (mi &a, int b) { return a = a ^ b; }

		mi & operator ++ () { return *this += 1; }
		const mi operator ++ (int) { mi t = *this; *this += 1; return t; }
		mi & operator -- () { return *this -= 1; }
		const mi operator -- (int) { mi t = *this; *this -= 1; return t; }

		friend bool operator == (mi a, mi b) { return a.x == b.x; }
		friend bool operator != (mi a, mi b) { return a.x != b.x; }
};
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	fa[x] = y, siz[y] += siz[x];
}

int main() {
	read(n, m, mod);
	for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; ++i) {
		int x, y; read(x, y);
		merge(x, y);
	}
	mi ans = 1;
	for (int i = 1; i <= n; ++i) {
		int f = get(i);
		if (!f) continue;
		if (siz[f] == n) return write(1 % mod, '\n'), 0;
		ans *= siz[f];
		if (++k > 2) ans *= n;
		fa[f] = 0;
	}
	write(ans.x, '\n');
	return 0;
}