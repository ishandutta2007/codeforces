#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
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

const int maxn = 4010;
typedef mint <998244353> mi;
int n,m,b[maxn],c[maxn];
mi pw2[maxn * maxn];
char a[maxn][maxn];

int fa[maxn], siz[maxn], deg[maxn], w[maxn];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	fa[x] = y, siz[y] += siz[x], deg[y] += deg[x], w[y] ^= w[x];
}

int main() {
	pw2[0] = 1;
	for (int i = 1; i <= 4000000; ++i) pw2[i] = pw2[i - 1] * 2;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
	if (n % 2 == 1 && m % 2 == 0) {
		for (int i = 1; i <= max(n, m); ++i)
			for (int j = 1; j < i; ++j)
				swap(a[i][j], a[j][i]);
		swap(n, m);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == '1') b[i] ^= 1, c[j] ^= 1;
	if (n % 2 == 0 && m % 2 == 0) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cnt += a[i][j] == '?';
		printf("%d\n", pw2[cnt].x);
	}
	else if (n % 2 == 1 && m % 2 == 1) {
		for (int i = 1; i <= n + m; ++i) siz[i] = 1, fa[i] = i;
		for (int i = 1; i <= n; ++i) w[i] = b[i];
		for (int i = 1; i <= m; ++i) w[i + n] = c[i];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (a[i][j] == '?') deg[i]++, deg[j + n]++;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (a[i][j] == '?') merge(i, j + n);
		mi cnt[2] = {1, 1};
		for (int i = 1; i <= n + m; ++i) {
			int f = get(i);
			if (!f) continue;
			fa[f] = 0;
			int p = siz[f], q = deg[f] / 2, r = w[f];
			for (int o = 0; o < 2; ++o)
				cnt[o] *= (r == (p & 1 ? o : 0) ? pw2[q - p + 1] : 0);
		}
		printf("%d\n", (cnt[0] + cnt[1]).x);
	}
	else {
		mi ans = 0;
		for (int o = 0; o < 2; ++o) {
			mi res = 1;
			for (int i = 1; i <= n; ++i) {
				int cnt = 0;
				for (int j = 1; j <= m; ++j)
					cnt += a[i][j] == '?';
				if (cnt == 0) res *= (b[i] == o);
				else res *= pw2[cnt - 1];
			}
			ans += res;
		}
		printf("%d\n", ans.x);
	}
	return 0;
}