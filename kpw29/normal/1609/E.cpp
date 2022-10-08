#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
vector <mint> fac, inv;
mint binom(int n, int k) {
	if (n < k || n < 0) return 0;
	return fac[n] * inv[k] * inv[n-k];
}

void prep(int N) {
	fac.resize(N+1, 1); inv.resize(N+1, 1);
	for (int i=1; i<=N; ++i) fac[i] = fac[i-1] * i;
	inv[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) inv[i] = inv[i+1] * (i + 1);
}*/

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
const int maxn = 1000100;


#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace atcoder;

struct S {
	vi dp;
	
	int maks() {
		int ret = 0;
		rep(i, 0, 32) ret = max(ret, dp[i]);
		return ret;
	}
};

int DL = 0;
int praweok[35];

//a, b, c, ab, bc

S id() {
	S tmp;
	tmp.dp.resize(32, 0);
	return tmp;
}

void maxuj(int &x, int val) { x = max(x, val); }
int get_mask(int a, int b, int c, int ab, int bc) {
	return a + (b << 1) + (c << 2) + (ab << 3) + (bc << 4);
}

S op(S lewy, S prawy) {
	DL = 0;
	rep(i, 0, 32) {
		if (prawy.dp[i]) praweok[DL++] = i;
	}
	
	S ret = id();
	rep(i, 0, 32) {
		ret.dp[i] = max(ret.dp[i], max(lewy.dp[i], prawy.dp[i]));
	}
	
	for (int i=0; i<32; ++i) {
		if (!lewy.dp[i]) continue;
		rep(xd, 0, DL){
			int j = praweok[xd];
			
			bool la = (i & (1 << 0));
			bool lb = (i & (1 << 1));
			bool lc = (i & (1 << 2));
			bool lab = (i & (1 << 3));
			bool lbc = (i & (1 << 4));
			
			bool ra = (j & (1 << 0));
			bool rb = (j & (1 << 1));
			bool rc = (j & (1 << 2));
			bool rab = (j & (1 << 3));
			bool rbc = (j & (1 << 4));
			
			if (la & rbc) continue;
			if (lab & rc) continue;
			
			int mask = get_mask(la | ra, lb | rb, lc | rc, 
			lab | rab | (la & rb), 
			lbc | rbc | (lb & rc));
			
			maxuj(ret.dp[mask], lewy.dp[i] + prawy.dp[j]);
		}
	}
	
	return ret;
}

bool TEST = 0;

void print(S all) {
	//rep(i, 0, 32) cout << all.dp[i] << ' ';
	//cout << endl;
}

S get_init(char znak) {
	S tmp = id();
	int a = 0, b = 0, c = 0, ab = 0, bc = 0;
	if (znak == 'a') a = 1;
	if (znak == 'b') b = 1;
	if (znak == 'c') c = 1;
	
	int mask = get_mask(a, b, c, ab, bc);
	tmp.dp[mask] = 1;
	
	return tmp;
}

void solve(int tc) {
	int n, m;
	cin >> n >> m;
	string s;
	if (!TEST) cin >> s;
	else {
		rep(i, 0, n) s += ('a' + random(0, 2));
	}
	
	vector <S> vec;
	rep(i, 0, n) {
		auto in = get_init(s[i]);
		print(in);
		vec.pb(in);
	}
		
	segtree<S, op, id> tree(vec);
	
	while (m--) {
		int pos; char znak;
		if (!TEST) {
			cin >> pos >> znak; --pos;
		}
		else {
			znak = ('a' + random(0, 2));
			pos = random(0, n-1);
		}
		tree.set(pos, get_init(znak));
		
		auto all = tree.all_prod();
		
		cout << n - all.maks() << "\n";
	}
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}