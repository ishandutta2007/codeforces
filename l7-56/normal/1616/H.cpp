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

const int maxn = 2e5 + 10, maxm = 1e7 + 10, mod = 998244353;
typedef mint <mod> mi;
int n, a[maxn], x, trie[maxm][2], siz[maxm], tot = 1;
mi pw2[maxn];

mi dfs(int u, int v, int bit) {
	if (!u) return pw2[siz[v]];
	if (!v) return pw2[siz[u]];
	if (bit < 0) return pw2[u == v ? siz[u] : siz[u] + siz[v]];
	if (u == v) {
		int c = (x >> bit) & 1, ls = trie[u][0], rs = trie[u][1];
		if (c) return dfs(ls, rs, bit - 1);
		else return dfs(ls, ls, bit - 1) + dfs(rs, rs, bit - 1) - 1;
	}
	else {
		int c = (x >> bit) & 1, lu = trie[u][0], ru = trie[u][1], lv = trie[v][0], rv = trie[v][1];
		if (c) return dfs(lu, rv, bit - 1) * dfs(ru, lv, bit - 1);
		else
			return dfs(lu, lv, bit - 1) + dfs(ru, rv, bit - 1) - 1 +
				(pw2[siz[lu]] - 1) * (pw2[siz[ru]] - 1) + (pw2[siz[lv]] - 1) * (pw2[siz[rv]] - 1);
	}
}

int main() {
	read(n, x);
	pw2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		pw2[i] = pw2[i - 1] * 2;
		int u = 1;
		for (int j = 30; j >= 0; --j) {
			int c = (a[i] >> j) & 1;
			if (!trie[u][c]) trie[u][c] = ++tot;
			siz[u]++, u = trie[u][c];
		}
		siz[u]++;
	}
	write((dfs(1, 1, 30) - 1).x, '\n');
	return 0;
}