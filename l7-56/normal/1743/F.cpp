// LUOGU_RID: 90747819
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
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

const int maxn = 3e5 + 10, N = 3e5, mod = 998244353;
typedef mint <mod> mi;
int n, L1, R1;
struct mat {
	mi a[2][2];
	mat() { a[0][0] = a[1][1] = 1, a[0][1] = a[1][0] = 0; }
	mat(int x) { a[0][0] = a[1][1] = x, a[0][1] = a[1][0] = 0; }
	friend mat operator * (mat p, mat q) {
		mat res = 0;
		res.a[0][0] = p.a[0][0] * q.a[0][0] + p.a[0][1] * q.a[1][0];
		res.a[1][0] = p.a[1][0] * q.a[0][0] + p.a[1][1] * q.a[1][0];
		res.a[0][1] = p.a[0][0] * q.a[0][1] + p.a[0][1] * q.a[1][1];
		res.a[1][1] = p.a[1][0] * q.a[0][1] + p.a[1][1] * q.a[1][1];
		return res;
	}
} A[2], a[maxn];

struct SegTree {
	mat val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void tag(int rt, mat v) { val[rt] = val[rt] * v; }
	void push_down(int rt) { tag(ls, val[rt]), tag(rs, val[rt]), val[rt] = mat(); }
	void update(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return tag(rt, A[0]);
		if (L <= l && r <= R) return tag(rt, A[1]);
		push_down(rt), update(ls, l, mid, L, R), update(rs, mid + 1, r, L, R);
	}
	void solve(int rt, int l, int r) {
		if (l == r) return a[l] = val[rt], void();
		push_down(rt), solve(ls, l, mid), solve(rs, mid + 1, r);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	read(n, L1, R1);
	A[0].a[0][0] = 3, A[0].a[0][1] = 0, A[0].a[1][0] = 1, A[0].a[1][1] = 2;
	A[1].a[0][0] = 1, A[1].a[0][1] = 2, A[1].a[1][0] = 1, A[1].a[1][1] = 2;
	for (int i = 2; i <= n; ++i) {
		int l, r; read(l, r);
		tr.update(1, 0, N, l, r);
	}
	tr.solve(1, 0, N);
	mi ans = 0;
	for (int i = 0; i <= N; ++i) ans += a[i].a[L1 <= i && i <= R1][1];
	write(ans.x, '\n');
	return 0;
}