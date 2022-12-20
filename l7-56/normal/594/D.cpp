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

const int maxn = 1e6 + 10, A = 1e6, mod = 1e9 + 7;
typedef mint <mod> mi;
int n, q, a[maxn], v[maxn], pr[maxn], cntp, lst[maxn];
mi ans[maxn], sp[maxn];
pii t[maxn];
vi b[maxn];
struct SegTree {
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	mi mul[maxn << 2];
	void tag(int rt, mi v) { mul[rt] *= v; }
	void push_down(int rt) { if (mul[rt].x != 1) tag(ls, mul[rt]), tag(rs, mul[rt]), mul[rt] = 1; }
	void build(int rt, int l, int r) {
		mul[rt] = 1;
		if (l == r) return;
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	void update(int rt, int l, int r, int L, int R, mi v) {
		if (L > R || L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, v);
		push_down(rt), update(ls, l, mid, L, R, v), update(rs, mid + 1, r, L, R, v);
	}
	mi query(int rt, int l, int r, int pos) {
		if (l == r) return mul[rt];
		return push_down(rt), pos <= mid ? query(ls, l, mid, pos) : query(rs, mid + 1, r, pos);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	for (int i = 2; i <= A; ++i) {
		if (!v[i]) v[i] = i, pr[++cntp] = i, sp[i] = mi(i - 1) / i;
		for (int j = 1; j <= cntp; ++j) {
			if (v[i] < pr[j] || (ll) i * pr[j] > A) break;
			v[i * pr[j]] = pr[j];
		}
	}
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	read(q);
	for (int i = 1; i <= q; ++i) read(t[i].fir, t[i].sec), b[t[i].sec].push_back(i);
	tr.build(1, 1, n);
	for (int r = 1; r <= n; ++r) {
		tr.update(1, 1, n, 1, r, a[r]);
		for (int tmp = a[r]; tmp > 1; ) {
			int p = v[tmp];
			while (tmp % p == 0) tmp /= p;
			tr.update(1, 1, n, lst[p] + 1, r, sp[p]);
			lst[p] = r;
		}
		for (int i : b[r]) ans[i] = tr.query(1, 1, n, t[i].fir);
	}
	for (int i = 1; i <= q; ++i) write(ans[i].x, '\n');
	return 0;
}