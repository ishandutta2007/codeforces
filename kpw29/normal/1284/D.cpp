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

//Did you REAALLY consider sample tests?
template <class S, S(*op)(S, S), S(*e)(),
class F, S (*mapping)(F, S), F(*composition)(F, F), F (*id)()>
struct lazy_segtree {
private:
	int n, size, log;
	vector <S> d; vector <F> lz;
	void update(int k) {d[k] = op(d[k << 1], d[k << 1 | 1]); }
	void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if (k < size) lz[k] = composition(f, lz[k]);
	}
	void push(int k) {
		all_apply(k << 1, lz[k]);
		all_apply(k << 1 | 1, lz[k]);
		lz[k] = id();
	}
	void make_pushes(int &l, int &r) {
		l += size; r += size;
		for (int i = log; i > 0; --i) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push(r >> i);
		}
	}
public:
	lazy_segtree(const vector <S> &v) : n(sz(v)) {
		log = 32 - __builtin_clz(n); size = 1 << log;
		d = vector<S>(2*size, e());
		lz = vector<F>(size, id());
		rep(i, 0, n) d[size + i] = v[i];
		for (int i=size-1; i>0; --i) update(i);
	}
    void set(int p, S x) {
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    S prod(int l, int r) {
		if (l >= r) return e();
		make_pushes(l, r);
		S sml = e(), smr = e();
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
		}
		return op(sml, smr);
	}
	void apply(int l, int r, F f) {
		if (l >= r) return;
		make_pushes(l, r);
		int initl = l, initr = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) all_apply(l++, f);
			if (r & 1) all_apply(--r, f);
		}
		l = initl; r = initr;
		rep(i, 1, log+1) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}
};

struct S{
    int MIN; int MAX;
};

S op(S a, S b) {
    return S{min(a.MIN, b.MIN), max(a.MAX, b.MAX)};
}
S id() { return S{INT_MAX, INT_MIN}; }

S apply(S a, S fn) {
    return op(a, fn);
}
S composition(S f1, S f2) {
    return op(f1, f2);
}
S e() {
    return id();
}

vector <pii> skal(vector <pii> vec) {
    vi ciag;
    map<int, int> M;
    trav(u, vec) {
        ciag.pb(u.e1);
        ciag.pb(u.e2);
    }
    sort(all(ciag));
    rep(i, 0, sz(ciag)) M[ciag[i]] = i;
    rep(i, 0, sz(vec)) {
        vec[i].e1 = M[vec[i].e1];
        vec[i].e2 = M[vec[i].e2];
    }
    return vec;
}

bool isect(vector <pii> A, vector <pii> B) {
    int n = 2 * sz(A) + 1;
    vector <S> vec(n, id());
    lazy_segtree<S, op, id, S, apply, composition, e> tree(vec);
    
    rep(i, 0, sz(A)) {
        tree.apply(A[i].e1, A[i].e2 + 1, S{B[i].e2, B[i].e1}); //minimalny prawy koniec, maksymalny lewy
    }
    
    
    rep(i, 0, n) {
        S elem = tree.prod(i, i+1);
        if (elem.MIN < elem.MAX) return false;
    }
    
    return true;
}

void solve(int tc) {
	int n, m;
	cin >> n;
	vector <pii> A(n);
	vector <pii> B(n);
	
	rep(i, 0, n) {
	    int a, b, c, d;
	    cin >> a >> b >> c >> d;
	    A[i] = {a, b};
	    B[i] = {c, d};
	}
	A = skal(A);
	B = skal(B);
	bool ans = isect(A, B);
	ans &= isect(B, A);
	
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}