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
void solve(int tc) {
	int n; cin >> n;
	vi ciag(n+1);
	ciag[0] = 0;
	map<int, int> occ;
	FOR(i, 1, n) {
		cin >> ciag[i];
		occ[ciag[i]]++;
	}
	trav(u, occ) {
		int ile = u.e2;
		if (ile % 2 == 1) TCOUT("-1");
	}
	//possible
	
	vi tandems = {};
	vector<pii> ops = {};
	int tansz = 0;
	
	auto insert_range = [&](int x, int y, int start_after) { //all elem
		debug("Odwracam", x, y, start_after);
		int len = y - x + 1;
		if (len < 1) return;
		vi newciag(start_after + 1); FOR(i, 0, start_after) newciag[i] = ciag[i];
		FOR(i, 1, len) {
			ops.pb({start_after + i - 1, ciag[x + i - 1]});
		}
		FOR(i, x, y) newciag.pb(ciag[i]);
		for (int i=y; i>=x; --i) newciag.pb(ciag[i]);
		
		rep(i, start_after + 1, sz(ciag)) newciag.pb(ciag[i]);
		debug(ciag);
		debug(newciag);
		ciag = newciag;
	};
	
	auto add_tandem = [&](int len) {
		tansz += len;
		tandems.pb(len);
	};
	int iter = 0;
	while (tansz + 1 != sz(ciag)) {
		++iter;
		map<int, int> jest;
		int pocz = tansz + 1;
		int firstocc = -1;
		int kon = -1;
		int different = 0;
		bool flag = 0;
		for (int j = tansz + 1; j < sz(ciag); ++j) {
			if (jest.find(ciag[j]) != jest.end()) {
				//robimy cos
				kon = j;
				firstocc = jest[ciag[j]];
				flag = 1;
				break;
			}
			jest[ciag[j]] = j;
			++different;
		}
		assert(flag);
		debug(tansz, pocz, firstocc);
		// do operation!
		if (pocz == firstocc) { // no need to rotate front
			insert_range(pocz + 1, kon - 1, kon);
			int ile_roznych = kon - pocz;
			add_tandem(2 * ile_roznych);
		}
		else {
			assert(pocz < firstocc);
			insert_range(pocz, firstocc, firstocc);
			add_tandem(2 * (firstocc - pocz + 1));
		}
		
		debug(tansz, ciag);
		debug(tandems);
		//if (iter > 1) exit(0);
	}
	
	cout << sz(ops) << "\n";
	for (auto [p, c] : ops) cout << p << ' ' << c << "\n";
	cout << sz(tandems) << "\n";
	trav(tan, tandems) cout << tan << ' ';
	cout << "\n";
}

int main() {
	boost;
	int tests = 1;
	cin >> tests;
	FOR(test, 1, tests) {
		solve(test);
	}
}