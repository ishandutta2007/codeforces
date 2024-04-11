#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
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

const int maxn = 5e5 + 10;
int n,a[maxn];
vector <int> pos[maxn];
template <int base, int mod>
struct Hash {
	typedef mint <mod> mi;
	mi pw[maxn],val;
	int cnt[maxn];
	Hash() {
		pw[0] = 1;
		for (int i = 1; i <= 500000; ++i) pw[i] = pw[i - 1] * base;
	}
	void update(int pos) {
		val -= pw[pos - 1] * cnt[pos];
		cnt[pos] = (cnt[pos] + 1) % 3;
		val += pw[pos - 1] * cnt[pos];
	}
	int gethash() { return val.x; }
};
Hash <131, 1000000007> h1;
Hash <151, 998244353> h2;
pii hs[maxn];
map <pii, int> s;
ll ans;

int main() {
	read(n);
	s[hs[0]] = 1;
	for (int i = 1, j = 0; i <= n; ++i) {
		read(a[i]);
		h1.update(a[i]), h2.update(a[i]);
		hs[i] = make_pair(h1.gethash(), h2.gethash());
		pos[a[i]].push_back(i);
		if (pos[a[i]].size() >= 4) {
			int J = pos[a[i]][pos[a[i]].size() - 4];
			while (j < J) s[hs[j++]]--;
		}
		ans += s[hs[i]];
		s[hs[i]]++;
	}
	write(ans, '\n');
	return 0;
}