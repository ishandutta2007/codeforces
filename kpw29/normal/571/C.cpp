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
struct BipartiteMatcher {
  vector<vector<int>> G;
  vector<int> L, R, Viz;
  
  BipartiteMatcher(int n, int m) :
  G(n), L(n, -1), R(m, -1), Viz(n) {}
  
  void AddEdge(int a, int b) {
    G[a].push_back(b);
  }
  
  bool Match(int node) {
    if (Viz[node])
      return false;
    Viz[node] = true;
    
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    return false;
  }
  
  int Solve() {
    int ok = true;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1)
          ok |= Match(i);
    }
    
    int ret = 0;
    for (int i = 0; i < L.size(); ++i)
      ret += (L[i] != -1);
    return ret;
  }
};

map <int, vector<pii> > M;
vi v[200100];
bool ans[200100];
vector<int> sat;

void przypisz(int zbior, int elem) {
	debug("Przypisuje", zbior, elem);
	bool flag = false;
	trav(cos, v[zbior]) {
		if (abs(cos) == elem) {
			flag = 1;
			if (cos > 0) ans[elem] = 1;
			else ans[elem] = 0;
		}
	}
	assert(flag);
	sat[zbior] = 1;
}
int sgn(int x) { return x > 0 ? 1 : 0; }

vi newclauses;
int init[maxn];

void solve(int tc) {
	int clauses, vars;
	cin >> clauses >> vars;
	sat.resize(clauses + 1, false);
	
	FOR(i, 1, clauses) {
		int k;
		cin >> k;
		rep(j, 0, k) {
			int val;
			cin >> val;
			v[i].pb(val);
			M[abs(val)].pb({i, val});
		}
	}
	
	vector <vi> graf(clauses);
	
	trav(xd, M) {
		auto &[val, vec] = xd;
		assert(sz(vec) <= 2);
		
		if (sz(vec) == 1) {
			przypisz(vec[0].e1, val);
		}
		else {
			if (vec[0].e1 == vec[1].e1) przypisz(vec[0].e1, val);
			else { //the only interesting case
				if (sgn(vec[0].e2) == sgn(vec[1].e2)) {
					przypisz(vec[0].e1, val);
					przypisz(vec[1].e1, val);
				}
				else {
					auto add_edge = [&](int zb, int var) {
						graf[zb - 1].pb(var - 1);
					};
					add_edge(vec[0].e1, val);
					add_edge(vec[1].e1, val);
				}
			}
		}
	}
	
	vector <vi> newgraf;
	debug(sat);
	
	rep(i, 0, clauses) {
		if (!sat[i + 1]) {
			init[sz(newgraf)] = i;
			newgraf.pb(graf[i]);
		}
	}
	
	debug("Ending");
	debug(graf);
	
	debug(newgraf);
	
	
	BipartiteMatcher matcher(sz(newgraf), vars);
	rep(i, 0, sz(newgraf)) {
		trav(u, newgraf[i]) matcher.AddEdge(i, u);
	}
	
	matcher.Solve();
	rep(i, 0, matcher.L.size()) {
		if (matcher.L[i] != -1) {
			int zb = init[i], var = matcher.L[i];
			przypisz(zb + 1, var + 1);
		}
	}

	
	FOR(i, 1, clauses) {
		if (!sat[i]) OUT("NO");
	}
	
	cout << "YES\n";
	FOR(i, 1, vars) cout << ans[i];
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