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

const int maxn = (1 << 18) + 10, mod = 998244353;
typedef mint <mod> mi;
int n;
char s[maxn];

pair <mi, string> dfs(int u) {
	if ((u << 1) >= (1 << n)) return make_pair(mi(1), (string)"" + s[u]);
	auto pl = dfs(u << 1), pr = dfs(u << 1 | 1);
	if (pl.second > pr.second) swap(pl, pr);
	mi res = pl.first * pr.first;
	if (pl.second != pr.second) res *= 2;
	return make_pair(res, s[u] + pl.second + pr.second);
}

int main() {
	scanf("%d%s", &n, s + 1);
	printf("%d\n", dfs(1).first.x);
	return 0;
}