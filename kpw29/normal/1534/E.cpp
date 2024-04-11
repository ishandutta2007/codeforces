#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
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
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
//#include <atcoder/maxflow>
//using namespace atcoder;

/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

mint fac[maxn], ifac[maxn];

inline mint dwumian(int n, int k) {
	if (n < 0 || n < k) return 0;
	return fac[n] * ifac[k] * ifac[n-k];
}

void precalc(int N) {
	fac[0] = ifac[0] = 1;
	FOR(i, 1, N) fac[i] = fac[i-1] * i;
	ifac[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) {
		ifac[i] = ifac[i + 1] * (i + 1);
	}
}*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 510;
const int mod = 1e9+7;
int init[maxn];
bool LOCAL = 0;
vector <int> v[maxn];

int n, k;

bool possible(int d) {
	/*
	//n items, then d sets, flow something
	mf_graph<int> g(n + d + 2);
	for (int i=1; i<=n; ++i) g.add_edge(0, i, d);
	FOR(i, 1, n) {
		FOR(j, 1, d) g.add_edge(i, j+n, 1);
	}
	
	FOR(j, 1, d) g.add_edge(j+n, n+d+1, k);
	int best_answer = g.flow(0, n+d+1);
	bool wynik = (best_answer == k * d);
	
	if (wynik) {
		auto edges = g.edges();
		FOR(i, 1, d) v[i].clear();
		trav(e, edges) {
			if (1 <= e.from && e.from <= n && e.flow > 0) {
				v[e.to - n].pb(e.from);
			}
		}
		
		FOR(i, 1, d) assert((int)v[i].size() == k);
	}
	
	return wynik;*/
	
	
	vector <pii> ile(n);
	FOR(i, 1, n) ile[i-1] = {1, i};
	int zostalo = d * k - n;
	assert(zostalo >= 0);
	assert(zostalo % 2 == 0);

	while (zostalo > 0) {
		FOR(i, 0, n-1) {
			if (zostalo > 0) {
				ile[i].e1 += 2;
				zostalo -= 2;
			}
		}
	}
	
	bool wynik = 1;
	//debug(d);
	FOR(steps, 1, d) {
		v[steps].clear();
		if (!wynik) break;
		sort(all(ile), greater<pii>());
		FOR(i, 0, k-1) {
			if (ile[i].e1 == 0) {
				wynik = 0;
				break;
			}
			ile[i].e1--;
			v[steps].pb(ile[i].e2);
		}
		
		//debug(v[steps]);
	}
	
	trav(u, ile) {
		if (u.e1 != 0) wynik = 0;
	}
	
	return wynik;
}

int main() {
	cin >> n >> k;
	vector <int> queries = {};
	FOR(q, 1, n) {
		int total = k * q;
		if (total >= n && total % 2 == n % 2) queries.pb(q);
	}
	
	if (queries.empty()) {
		cout << -1 << endl;
		return 0;
	}
	
	if (LOCAL) {
		FOR(i, 1, n) cin >> init[i];
	}
	
	/*int sz = queries.size();
	int x = 0, y = sz - 1;
	while (x < y) {
		int sr = (x + y) / 2;
		if (!possible(queries[sr])) x = ++sr;
		else y = sr;
	}*/
	int x = 0;
	while (!possible(queries[x])) ++x;
	//debug(queries);
	
	int result = queries[x];
	//debug(result);
	int ans;
	ans = possible(result);
	assert(ans);
	int ksor = 0;
	FOR(i, 1, result) {
		cout << "? ";
		trav(u, v[i]) cout << u << ' ';
		cout << endl;
		int odp = 0;
		if (LOCAL) {
			trav(node, v[i]) odp ^= init[node];
		}
		else {
			cin >> odp;
		}
		
		ksor ^= odp;
	}
	
	cout << "! " << ksor << endl;
}