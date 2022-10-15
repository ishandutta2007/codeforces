#include <bits/stdc++.h>

using namespace std;

template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using Mint = ModInt<1000000007U>;
// using Mint = ModInt<998244353U>;

namespace seg {
typedef int LL;
const LL Inf = 1e9;
const int MN = 200005, MS = 1 << 19 | 7;

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
struct dat {
	LL sum;
	LL mx1, mx2, mn1, mn2;
	int mxc, mnc;
//	char *Print() {
//		char s[99];
//		sprintf(s, "(%lld, (%lld, %lld, %d), (%lld, %lld, %d))", sum, mx1, mx2, mxc, mn1, mn2, mnc);
//		return s;
//	}
	dat() {}
	friend dat operator + (dat a, dat b) {
//		printf("%s + %s\n", a.Print(), b.Print());
		a.sum += b.sum;
		if (a.mx1 < b.mx1) {
			a.mx2 = std::max(a.mx1, b.mx2);
			a.mx1 = b.mx1, a.mxc = b.mxc;
		} else if (a.mx1 == b.mx1) {
			a.mxc += b.mxc;
			a.mx2 = std::max(a.mx2, b.mx2);
		} else a.mx2 = std::max(a.mx2, b.mx1);
		if (a.mn1 > b.mn1) {
			a.mn2 = std::min(a.mn1, b.mn2);
			a.mn1 = b.mn1, a.mnc = b.mnc;
		} else if (a.mn1 == b.mn1) {
			a.mnc += b.mnc;
			a.mn2 = std::min(a.mn2, b.mn2);
		} else a.mn2 = std::min(a.mn2, b.mn1);
		return a;
	}
} tr[MS];
int len[MS]; LL tlb[MS], tub[MS], tbi[MS];
inline void P(int i, LL lb, LL ub, LL bi) {
	if (tr[i].mx1 == tr[i].mn1) {
		if (tr[i].mx1 < lb) tr[i].mx1 = tr[i].mn1 = lb, tr[i].sum = lb * len[i];
		if (ub < tr[i].mn1) tr[i].mx1 = tr[i].mn1 = ub, tr[i].sum = ub * len[i];
	} else if (tr[i].mx1 == tr[i].mn2) {
		if (ub < tr[i].mx1) tr[i].sum -= (tr[i].mx1 - ub) * tr[i].mxc, tr[i].mx1 = tr[i].mn2 = ub;
		if (tr[i].mn1 < lb) tr[i].sum += (lb - tr[i].mn1) * tr[i].mnc, tr[i].mn1 = tr[i].mx2 = lb;
	} else {
		if (ub < tr[i].mx1) tr[i].sum -= (tr[i].mx1 - ub) * tr[i].mxc, tr[i].mx1 = ub;
		if (tr[i].mn1 < lb) tr[i].sum += (lb - tr[i].mn1) * tr[i].mnc, tr[i].mn1 = lb;
	}
	tr[i].sum += bi * len[i];
	tr[i].mx1 += bi, tr[i].mx2 += bi;
	tr[i].mn1 += bi, tr[i].mn2 += bi;
	lb -= tbi[i], ub -= tbi[i], tbi[i] += bi;
	if (tub[i] < lb) tub[i] = lb;
	if (ub < tlb[i]) tlb[i] = ub;
	tlb[i] = std::max(tlb[i], lb);
	tub[i] = std::min(tub[i], ub);
}
inline void Pushdown(int i) {
	if (tlb[i] != -Inf || tub[i] != Inf || tbi[i]) {
		P(li, tlb[i], tub[i], tbi[i]);
		P(ri, tlb[i], tub[i], tbi[i]);
		tlb[i] = -Inf, tub[i] = Inf, tbi[i] = 0;
	}
}
void Build(int i, int l, int r) {
	len[i] = r - l + 1;
	if (l == r) {
		LL x = 1;
		// scanf("%lld", &x);
		tr[i].sum = tr[i].mx1 = tr[i].mn1 = x;
		tr[i].mx2 = -Inf, tr[i].mn2 = Inf;
		tr[i].mxc = tr[i].mnc = 1;
//		printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print());
		return ;
	}
	Build(ls), Build(rs);
	tr[i] = tr[li] + tr[ri];
	tlb[i] = -Inf, tub[i] = Inf, tbi[i] = 0;
//	printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print());
}
void Mdfmax(int i, int l, int r, int a, int b, LL x) {
	if (r < a || b < l || x <= tr[i].mn1) return ;
	if (a <= l && r <= b && x < tr[i].mn2) return P(i, x, Inf, 0)/*, printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print()), void()*/;
	Pushdown(i), Mdfmax(ls, a, b, x), Mdfmax(rs, a, b, x);
	tr[i] = tr[li] + tr[ri];
//	printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print());
}
void Mdfmin(int i, int l, int r, int a, int b, LL x) {
	if (r < a || b < l || tr[i].mx1 <= x) return ;
	if (a <= l && r <= b && tr[i].mx2 < x) return P(i, -Inf, x, 0)/*, printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print()), void()*/;
	Pushdown(i), Mdfmin(ls, a, b, x), Mdfmin(rs, a, b, x);
	tr[i] = tr[li] + tr[ri];
//	printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print());
}
void Mdfadd(int i, int l, int r, int a, int b, LL x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, -Inf, Inf, x)/*, printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print()), void()*/;
	Pushdown(i), Mdfadd(ls, a, b, x), Mdfadd(rs, a, b, x);
	tr[i] = tr[li] + tr[ri];
//	printf("[%d : %d - %d] : %s\n", i, l, r, tr[i].Print());
}
LL Qur(int i, int l, int r, int a, int b) {
    if (a > b) return 0;
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return tr[i].sum;
	Pushdown(i);
	return Qur(ls, a, b) + Qur(rs, a, b);
}
}

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    seg::Build(1, 1, n);
    Tree mintree(n, 1e9);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 0)
                seg::Mdfmin(1, 1, n, l, r, 0);
            else
                mintree.update(l - 1, min(r - 1, mintree.query(l - 1, l)));
        } else {
            int x;
            cin >> x;
            if (seg::Qur(1, 1, n, x, x) == 0) {
                cout << "NO\n";
                continue;
            }
            int l = -1, r = x;
            while (r - l > 1) {
                int md = (l + r) / 2;
                if (seg::Qur(1, 1, n, md, x - 1) == 0)
                    r = md;
                else
                    l = md;
            }
            int rr = mintree.query(r - 1, x);
            if (rr < n && seg::Qur(1, 1, n, x + 1, rr + 1) == 0)
                cout << "YES\n";
            else
                cout << "N/A\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}