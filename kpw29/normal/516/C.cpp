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

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  private:
	int n, size;
	vector<S> d;
	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  public:
    segtree(const std::vector<S>& v) : n(sz(v)) {
		size = 1 << (32 - __builtin_clz(n));
        d = vector<S>(2 * size, e());
        rep(i, 0, n) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }
    void set(int pos, S val) {
        for (d[pos += n] = val; pos /= 2;)
			d[pos] = op(d[pos * 2], d[pos * 2 + 1]);
    }
    S get(int p) {return d[p + size];}
    S prod(int l, int r) {
        S sml = e(), smr = e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
			if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
        }
        return op(sml, smr);
    }
};

}  // namespace atcoder

using namespace atcoder;
/*using mint = modint998244353;
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
const ll INF = 1e18+3;

//Did you REAALLY consider sample tests?

struct S {
	ll max_left;
	ll max_right;
	ll result;
};

S id() {
	return S{-INF, -INF, -INF};
};

S op(S lewy, S prawy) {
	S ret = id();
	ret.max_left = max(lewy.max_left, prawy.max_left);
	ret.max_right = max(lewy.max_right, prawy.max_right);
	ret.result = max(lewy.result, prawy.result);
	ret.result = max(ret.result, lewy.max_left + prawy.max_right);
	return ret;
}

ll h[maxn], d[maxn];
ll pref[maxn];
int n, m;

int main() {
	vector <S> tmp;
	tmp.pb(id());
	
	boost;
	cin >> n >> m;
	pref[0] = 0;
	FOR(i, 1, n) {
		cin >> d[i];
		pref[i + 1] = pref[i] + d[i];
	}
	FOR(i, 1, n) cin >> h[i];
	
	FOR(i, 1, n) {
		pref[n + i + 1] = pref[n + i] + d[i];
	}
	
	FOR(i, 1, 2 * n) cerr << pref[i] << ' ';
	FOR(i, 1, n) {
		tmp.pb(S{h[i] * 2 - pref[i], h[i] * 2 + pref[i], -INF});
	}
	FOR(i, 1, n) {
		tmp.pb(S{h[i] * 2 - pref[i+n], h[i] * 2 + pref[i+n], -INF});
	}
	segtree<S, op, id> tree(tmp);
	while (m--) {
		int a, b;
		cin >> a >> b;
		pii query_incl;
		if (a > b) {
			query_incl = {b + 1, a - 1};
		}
		else {
			query_incl = {b + 1, a - 1 + n};
		}
		debug(query_incl);
		S pytaj = tree.prod(query_incl.e1, query_incl.e2 + 1);
		cout << pytaj.result << "\n";
	}
	
}