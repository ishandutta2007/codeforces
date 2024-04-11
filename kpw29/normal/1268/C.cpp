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

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
	private:
	int n, size, log;
	vector<S> d;
	void update(int k) {d[k] = op(d[2 * k], d[2 * k + 1]); }
	public:
	segtree(const vector <S>&v) : n(sz(v)) {
		log = (32 - __builtin_clz(n)); size = 1 << log;
		d = vector<S>(2*size, e());
		rep(i, 0, n) d[size+i] = v[i];
		for (int i = size - 1; i >= 1; --i) update(i);
	}
	void set(int pos, S val) {
		pos += size; d[pos] = val;
        rep(i, 1, log + 1) update(pos >> i);
	}
	S prod(int l, int r) {
		S sml = e(), smr = e();
		for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
		}
		return op(sml, smr);
	}
};

ll id() { return 0; }
ll op(ll a, ll b) { return a + b; }

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

/*void example() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).first;
	assert(it == t.lower_bound(9));
	assert(t.order_of_key(10) == 1);
	assert(t.order_of_key(11) == 2);
	assert(*t.find_by_order(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}*/


//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n;
	cin >> n;
	vi vec(n+1);
	FOR(i, 1, n) cin >> vec[i];
	vi perm(n+1);
	FOR(i, 1, n) perm[vec[i]] = i;
	
	vll rusz(n+1, 0), inver(n+1, 0);
	
	
	vll ini(n+1, id());
	segtree<ll, op, id> solver(ini);
	
	FOR(val, 1, n) {
		int gdzie = perm[val];
		inver[val] = inver[val - 1] + solver.prod(gdzie, n + 1);
		solver.set(gdzie, 1);
	}
	
	segtree<ll, op, id> tree(ini);
	
	Tree<int> secik;
	vi middle(n+1, 0);
	FOR(i, 1, n) {
		int half = (i + 1) / 2;
		secik.insert(perm[i]);
		middle[i] = *secik.find_by_order(half - 1);
	}
	
	auto f = [&](ll a) -> ll {
		return a * (a + 1) / 2;
	};
	
	auto get_sum = [&](ll a, ll b) -> ll {
		if (a > b) return 0LL;
		return f(b) - f(a-1);
	};
	
	FOR(i, 1, n) {
		int half = (i + 1) / 2;
		int key = middle[i];
		int lewo = half - 1;
		int prawo = i - half;
		debug(lewo, prawo);
		
		tree.set(perm[i], perm[i]);
		
		auto prawo_sum = tree.prod(key + 1, n + 1);
		auto lewo_sum = tree.prod(0, key);
		
		rusz[i] = get_sum(key - lewo, key - 1) - lewo_sum;
		rusz[i] += prawo_sum - get_sum(key + 1, key + prawo);
	}
	
	debug(middle);
	debug(rusz);
	debug(inver);
	FOR(i, 1, n) cout << rusz[i] + inver[i] << ' ';
	cout << "\n";
	
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