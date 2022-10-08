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
const double EPS = 1e-9;

/**
 * Author: Simon Lindholm
 * Date: 2019-12-31
 * License: CC0
 * Source: folklore
 * Description: Eulerian undirected/directed path/cycle algorithm.
 * Input should be a vector of (dest, global edge index), where
 * for undirected graphs, forward/backward edges have the same index.
 * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
 * empty list if no cycle/path exists.
 * To get edge indices back, add .second to s and ret.
 * Time: O(V + E)
 * Status: stress-tested
 */
 
vector<pii> eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
	vector <pii> ret, s = {{src, -1}};
	while (!s.empty()) {
		pii x = s.back();
		int y, e, &it = its[x.first], end = sz(gr[x.first]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x.first][it++];
		if (!eu[e]) {
			D[x.first]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

//Did you REAALLY consider sample tests?

void dfs(int x, vector<vector<pii> > &graf, vi &odw, vi &comp) {
	odw[x] = 1;
	comp.pb(x);
	for (auto &[u, id] : graf[x]) {
		if (!odw[u]) dfs(u, graf, odw, comp);
	}
}
const int DEB = 0;

void solve(int tc) {
	int n, m;
	if (!DEB) cin >> n >> m;
	else {
		n = rand()%10+1, m = min(n+rand()%20, n * (n - 1) / 2);
		if (n == 1) m = 0;
		debug(n, m);
	}
	
	set <pii> things;
	vector<pii> edges(m);
	vi reindex(n+m, -1);
	vi odwroc(n+m, -1);
	
	vector<vector<pii> > v(n + 1);
	vi ktory(n+1, 0);
	vi remove(n+m, 0);
	
	rep(i, 0, m) {
		int a, b;
		if (!DEB) cin >> a >> b;
		else {
			a = rand()%n+1, b = rand()%n+1;
			while (a == b || things.find({a,b}) != things.end()) {
				a = rand()%n+1, b = rand()%n+1;
			}
			
			things.insert({a, b});
			things.insert({b, a});
		}
		edges[i] = {a, b};
		v[a].pb({b, i});
		v[b].pb({a, i}); 
	}
	debug(n, m);
	debug(edges);
	
	vi odw(n+1, false);
	FOR(st, 1, n) {
		if (!odw[st]) {
			odw[0] = 1;
			v[0].clear();
			vi comp;
			dfs(st, v, odw, comp);
			
			trav(node, comp) {
				if (sz(v[node]) % 2) {
					v[0].pb({node, sz(edges)});
					v[node].pb({0, sz(edges)});
					edges.pb({0, node});
				}
			}
			
			comp.pb(0);
			reverse(all(comp));
			
			int NN = sz(comp);
			rep(i, 0, NN) {
				ktory[comp[i]] = i;
			}
			vector <vector<pii>> to_euler(NN);
			int ed = 0;
			rep(i, 0, NN) {
				int x = comp[i];
				for (auto [u, id] : v[x]) {
					if (reindex[id] == -1) {
						odwroc[ed] = id;
						reindex[id] = ed++;
					}
					to_euler[i].pb({ktory[u], reindex[id]});
				}
			}
			rep(i, 0, sz(to_euler)) debug(comp[i], to_euler[i]);
			debug(ed);
			if (ed == 0) continue;
			assert(comp[0] == 0);
			assert(ktory[0] == 0);
			
			vector<pii> cycle = eulerWalk(to_euler, ed, 0);
			debug(cycle);
			if(cycle.empty()) cycle=eulerWalk(to_euler, ed, 1);
			debug(edges);
			debug(reindex);
			debug(odwroc);
			
			vector <bool> ignored(sz(cycle), 0);
			int it = 1;
			for (auto [lol, rein] : cycle) {
				if (rein == -1) {
					continue;
				}
				int e = odwroc[rein];
				if (edges[e].e1 == 0 || edges[e].e2 == 0) {
					ignored[it] = 1;
					if (it > 1) ignored[it - 1] = 0;
				}
				else {
					if (it == 1 || it + 1 == sz(cycle)) ignored[it] = 0;
					else ignored[it] = 1 - ignored[it - 1];
				}
				
				++it;
			}
			
			for (it = 1; it < sz(cycle); ++it) {
				int rein = cycle[it].e2;
				int e = odwroc[rein];
				debug(cycle[it], rein, e);
				if (ignored[it] || edges[e].e1 == 0 || edges[e].e2 == 0) remove[e] = 1;
				else remove[e] = 0;
			}
			
			debug("cyc");
			for (int i=1; i<sz(cycle); ++i) {
				int e = odwroc[cycle[i].e2];
				debug(edges[e].e1, edges[e].e2, ignored[i]);
			}
		}
	}
	
	int cnt = 0;
	rep(i, 0, sz(edges)) cnt += 1-remove[i];
	cout << cnt << endl;
	vi deg(n+1, 0);
	
	rep(i, 0, sz(edges)) if (!remove[i]) {
		cout << edges[i].e1 << ' ' << edges[i].e2 << "\n";
		deg[edges[i].e1]++;
		deg[edges[i].e2]++;
	}
	
	FOR(i, 1, n) assert(deg[i] * 2 >= sz(v[i]));
}

int main() {
	boost;
	if(DEB) rep(step, 0, 1000) solve(1);
	solve(1);
}