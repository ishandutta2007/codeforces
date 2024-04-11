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

const ll INF = LLONG_MAX / 4;
pll opmax(pll a, pll b) {
	if (a.e1 > b.e1) return a;
	else return b;
}

pll idmax() { return {-INF, -1}; }

struct S {
	ll result, maxx, maxy;
};
S merge(S a, S b) {
	ll r = max({a.result, b.result, a.maxx + b.maxy});
	ll mx = max(a.maxx, b.maxx);
	ll my = max(a.maxy, b.maxy);
	return S{r, mx, my};
}

S id() {
	return S{-INF, -INF, -INF};
}

typedef pair<pii, int> inter;
//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n, m;
	cin >> n >> m;
	vector<vi> vec(3);
	vector<ll> s(n+2, 0), f(n+2, 0);
	
	rep(i, 0, 3) {
		vec[i].resize(n + 1);
		FOR(j, 1, n) cin >> vec[i][j];
	}
	
	FOR(i, 1, n) s[i] = s[i-1] + vec[0][i];
	for (int i=n; i>0; --i) {
		f[i] = f[i + 1] + vec[2][i];
	}
	
	debug(s); debug(f);
	vll psum(n+1, 0);
	FOR(i, 1, n) psum[i] = psum[i-1] + vec[1][i];
	debug(psum);
	
	vector<pll> vc(n+2);
	rep(i, 0, n+2) vc[i] = {s[i], i};
	
	vector <pair<pii, int> > intervals(m);
	rep(i, 0, m) {
		cin >> intervals[i].e1.e1 >> intervals[i].e1.e2 >> intervals[i].e2;
	}
	
	sort(all(intervals), [&](inter a, inter b) {
		if (a.e1.e2 != b.e1.e2) return a.e1.e2 < b.e1.e2;
		if (a.e1.e1 != b.e1.e1) return a.e1.e1 > b.e1.e1;
		return a.e2 < b.e2;
	});
	debug(intervals);
	vector<S> init(n+2, id());
	FOR(i, 1, n) {
		init[i] = S{f[i] + s[i] + vec[1][i], 
			s[i] - psum[i - 1], 
			f[i] + psum[i]
		};
	}
	
	segtree<S, merge, id> initsolver(init);
	
	vector<pll> sinit(n+2, idmax());
	FOR(i, 1, n) sinit[i] = {s[i] - psum[i - 1], i};
	segtree<pll, opmax, idmax> initializer(sinit);
	
	vector<pll> treeinit(n+2, idmax());
	FOR(i, 1, n) treeinit[i] = {-INF + 1, i};
	segtree<pll, opmax, idmax> tree(treeinit);
	
	vector<pll> finit(n+2, idmax());
	FOR(i, 1, n) finit[i] = {f[i] + psum[i], i};
	segtree<pll, opmax, idmax> finalizer(finit); //TODO
	
	
	ll res = -INF;
	
	vll dp(n + 2, -INF);
	rep(xd, 0, sz(intervals)) {
		auto [a, b] = intervals[xd].e1;
		int k = intervals[xd].e2;
		// find best initial values
		auto [init_val, init_pos] = initializer.prod(a, b + 1);
		debug(init_val, init_pos);
		dp[b] = max(dp[b], init_val + psum[b] - k);
		
		auto [value, pos] = tree.prod(a - 1, b + 1);
		debug(a, b, k);
		debug(value, pos);
		if (pos >= a - 1 && pos <= b) {
			//value - k + psum[ten] - psum[pos] + f[ten]
			debug("Gf", finalizer.prod(pos, b + 1).e1);
			res = max(res, finalizer.prod(pos, b + 1).e1 + value - k);
			debug(psum[b], value, k);
			dp[b] = max(dp[b], psum[b] + value - k);
		}
		
		debug(dp);
		auto g = tree.prod(b, b+1);
		if (g.e1 < dp[b] - psum[b]) g.e1 = dp[b] - psum[b];
		tree.set(b, g);
		// tylko ten przedzial pod uwage
		res = max(res, initsolver.prod(a, b + 1).result - k);
	}
	
	cout << res << "\n";
}

int main() {
	boost;
	int tests = 1;
	//cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}