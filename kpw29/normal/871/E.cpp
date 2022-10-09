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
typedef vector<pii> vpi;
//#include <atcoder/modint>
//using namespace atcoder;
//using mint = modint1000000007;
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
#ifdef DEBUG
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#endif

#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif
int n;

void dfs(int x, vector <vi> &graf, vi &odl) {
	for (auto u : graf[x]) {
		if (odl[u] == n) {
			odl[u] = 1 + odl[x];
			dfs(u, graf, odl);
		}
	}
}
void check(int root, vi &dist, vector <vi> &graf) {
	vi odl(n, n);
	odl[root] = 0;
	dfs(root, graf, odl);
	rep(i, 0, n) {
		if (odl[i] != dist[i]) OUT("-1");
	}
}

void solve(int tc) {
	int k;
	cin >> n >> k;
	vector <int> special;
	vector <vi> dist(n);
	rep(node, 0, k) {
		vi d(n, 0);
		int which = -1;
		rep(i, 0, n) {
			cin >> d[i];
			if (d[i] == 0) {
				if (which != -1) OUT("-1");
				which = i;
			}
		}
		if (which == -1) OUT("-1");
		special.pb(which);
		if (!dist[which].empty()) {
			rep(i, 0, n) {
				if (dist[which][i] != d[i]) OUT("-1");
			}
		}
		
		dist[which].insert(dist[which].end(), all(d));
	}
	
	sort(all(special));
	int root = special[0];
	vector <vi> v(n);
	vi par(n, -1);
	auto attach = [&](int a, int b) { //przypnij a do b
		assert(par[a] == -1);
		debug(a, b);
		par[a] = b;
		v[a].pb(b);
		v[b].pb(a);
	};
	
	vi closest(n, root);
	vi dist_closest(n);
	rep(i, 0, n) dist_closest[i] = dist[root][i];
	
	rep(drugi, root + 1, n) {
		if (dist[drugi].empty()) continue;
		vpi tab;
		int path_len = dist[root][drugi];
		if (dist[drugi][root] != path_len) OUT("-1");
		
		rep(i, 0, n) {
			int cand = dist[drugi][i] + dist[root][i];
			if (cand < path_len) OUT("-1");
			if (cand == path_len) tab.pb({dist[root][i], i});
		}
		
		sort(all(tab));
		debug(root, drugi);
		debug(tab);
		if (sz(tab) != path_len + 1) OUT("-1");
		if (tab[0].e2 != root) OUT("-1");
		
		FOR(i, 1, path_len) {
			if (tab[i].e1 != i) OUT("-1");
			int node = tab[i].e2;
			if (par[node] == -1) attach(node, tab[i-1].e2);
		}
		
		rep(i, 0, n) {
			int tot = dist[drugi][i] + dist[root][i] - path_len;
			if (tot % 2 != 0) OUT("-1");
			int limb = tot / 2;
			debug(i, limb);
			int d0 = dist[root][i] - limb;
			if (limb < dist_closest[i]) {
				dist_closest[i] = limb;
				closest[i] = tab[d0].e2;
			}
		}
	}
	
	
	// finding closest elements
	vi nodes;
	
	rep(i, 0, n) {
		nodes.pb(i);
	}
	
	sort(all(nodes), [&](int a, const int b) {
		int d1 = dist_closest[a];
		int d2 = dist_closest[b];
		if (d1 == d2) return a < b;
		return d1 < d2;
	});
	
	debug(nodes);
	vector <vi> candidates(n);
	par[root] = root;
	trav(node, nodes) {
		int d = dist_closest[node];
		int repr = closest[node];
		
		if (par[node] == -1) {
			int szu = d - 1;
			if (!(szu < sz(candidates[repr]))) OUT("-1");
			attach(node, candidates[repr][szu]);
		}
		
		if (d == sz(candidates[repr])) { //push new node
			candidates[repr].pb(node);
		}
	}
	
	// the tree is generated, only remains to check it
	debug("HERE");
	trav(node, special) {
		check(node, dist[node], v);
	}
	
	rep(i, 0, n) {
		if (i == root) continue;
		assert(par[i] != -1);
		cout << i + 1 << ' ' << par[i] + 1 << "\n";
	}
};

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}