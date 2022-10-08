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
typedef vector<pii> vpi;
//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n;
	cin >> n;
	vpi v(n+1);
	vi deltas(n+1);
	vi dest(n+1);
	FOR(i, 1, n) {
		cin >> v[i].e1;
		v[i].e2 = i;
	}
	FOR(i, 1, n) cin >> dest[i];
	sort(all(dest));
	sort(all(v));
	FOR(i, 1, n) deltas[i] = dest[i] - v[i].e1;
	debug(deltas);
	ll pref = 0;
	FOR(i, 1, n) {
		pref += deltas[i];
		if (pref < 0) OUT("NO");
	}
	if (pref != 0) OUT("NO");
	
	vector <pair<pii, int> > ans;
	vector <pii> stos;
	
	FOR(i, 1, n) {
		if (deltas[i] > 0) {
			int init_pos = v[i].e2;
			stos.pb({deltas[i], init_pos});
		}
		else {
			int skad_jestem = v[i].e2;
			while (deltas[i] < 0) {
				int brr = abs(deltas[i]);
				assert(!stos.empty());
				int ile_zmienie = min(brr, stos.back().e1);
				stos[sz(stos)-1].e1 -= ile_zmienie;
				deltas[i] += ile_zmienie;
				ans.pb({{stos.back().e2, skad_jestem}, ile_zmienie});
				if (stos[sz(stos)-1].e1 == 0) stos.pop_back();
			}
		}
	}
	
	cout << "YES\n";
	cout << sz(ans) << "\n";
	trav(u, ans) cout << u.e1.e1 << ' ' << u.e1.e2 << ' ' << u.e2 << "\n";
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