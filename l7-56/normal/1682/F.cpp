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

const int maxn = 2e5 + 10, mod = 1e9 + 7;
typedef mint <mod> mi;
int n, m, a[maxn], b[maxn];
ll da[maxn], sb[maxn];
mi ans[maxn];
pii q[maxn];

struct BIT {
	mi c[maxn];
	void add(int pos, mi val) { for (; pos <= n; pos += pos & (-pos)) c[pos] += val; }
	mi ask(int pos) {
		mi res = 0;
		for (; pos > 0; pos &= pos - 1) res += c[pos];
		return res;
	}
	mi ask(int l, int r) { return ask(r) - ask(l - 1); }
} tr1, tr2;

int main() {
	read(n, m);
	for (int i = 1; i <= n; ++i) read(a[i]), da[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; ++i) read(b[i]), sb[i] = sb[i - 1] + b[i];
	for (int i = 1; i <= m; ++i) read(q[i].fir, q[i].sec);
	for (int i = 1; i <= n; ++i)
		tr1.add(i, mi(sb[i - 1]) * da[i]), tr2.add(i, -da[i]);

	vector <int> pq(m), pa(n);
	iota(pq.begin(), pq.end(), 1);
	iota(pa.begin(), pa.end(), 0);
	sort(pq.begin(), pq.end(), [] (int x, int y) { return sb[q[x].fir - 1] < sb[q[y].fir - 1]; });
	sort(pa.begin(), pa.end(), [] (int x, int y) { return sb[x] < sb[y]; });
	int j = 0;
	for (int i : pq) {
		int l = q[i].fir, r = q[i].sec;
		while (j < n && sb[pa[j]] < sb[l - 1]) {
			int x = pa[j++];
			tr1.add(x + 1, 0 - mi(2) * sb[x] * da[x + 1]);
			tr2.add(x + 1, mi(2) * da[x + 1]);
		}
		ans[i] = tr1.ask(l, r) + tr2.ask(l, r) * sb[l - 1];
	}
	for (int i = 1; i <= m; ++i) write(ans[i].x, '\n');
	return 0;
}