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
	S all_prod() { return prod(0, n); }
};

template <bool VALS_EDGES,
class S, S(*op)(S, S), S(*e)(),
class F, S (*mapping)(F, S), F(*composition)(F, F), F (*id)()>
struct HLD {
	int N, tim = 0;
	vector <vi> adj;
	vi par, siz, depth, rt, pos, treeroot;
	lazy_segtree<S, op, e, F, mapping, composition, id> tree;
	HLD(vector <vi> adj_, vi roots={0}) : 
		N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		rt(N), pos(N), treeroot(N), tree(vector<S>(N, e())) {
		trav(root, roots) {
			rt[root] = treeroot[root] = root; 
			dfsSz(root); dfsHld(root);
		}
	}
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		trav(u, adj[v]){
			par[u] = v, depth[u] = depth[v] + 1;
			treeroot[u] = treeroot[v];
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		trav(u, adj[v]){
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template<class B> int process(int u, int v, B query) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			query(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		query(pos[u] + VALS_EDGES, pos[v] + 1);
		return u;
	}
	int lca(int u, int v) {
		return process(u, v, [](int l, int r) {});
	}
	void path_apply(int u, int v, F func) {
		debug("Path apply: ", u, v);
		process(u, v, [&](int l, int r) {tree.apply(l, r, func); });
	}
	S path_prod(int u, int v) {
		S res = e();
		process(u, v, [&](int l, int r) {
			res = op(res, tree.prod(l, r));
		});
		return res;
	}
	void subtree_apply(int v, F func) {
		tree.apply(pos[v] + VALS_EDGES, pos[v] + siz[v], func);
	}
	S subtree_prod(int v) {
		return tree.prod(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
	S all_prod() {return tree.prod(0, N);}
};

int n, zap;
vector <vi> graf;

void find_cycle(int x, vi &ids, vi &cycle) {
	ids[x] = sz(cycle);
	cycle.pb(x);
	trav(u, graf[x]) {
		if (ids[u] == -2) find_cycle(u, ids, cycle);
	}
}

struct S{
	int zeros, ones;
};

S op(S a, S b) {return S{a.zeros + b.zeros, a.ones + b.ones};}
S e() {return S{1, 0};}
bool composition(bool a, bool b) {
	return a ^ b;
}
S mapping(bool fn, S elem) {
	if (!fn) return elem;
	return S{elem.ones, elem.zeros};
}
bool id() {return false; }

int main() {
	boost;
	cin >> n >> zap;
	graf.resize(n);
	vi deg(n, 0);
	
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graf[a].pb(b);
		graf[b].pb(a);
		deg[a]++; deg[b]++;
	}
	
	queue<int> q;
	vi cycle_id(n, -2);
	
	rep(i, 0, n) {
		if (deg[i] == 1) q.push(i);
	}
	
	while (!q.empty()) {
		int x = q.front();
		cycle_id[x] = -1;
		q.pop();
		trav(nei, graf[x]) {
			deg[nei]--;
			if (deg[nei] == 1) q.push(nei);
		}
	}
	
	int st = -1;
	rep(i, 0, n) {
		if (cycle_id[i] != -1) st = i;
	}
	assert(st != -1);
	
	vi cycle;
	find_cycle(st, cycle_id, cycle);
	
	// generate HLD graf
	vector <vi> hldgraf(n);
	rep(i, 0, n) {
		trav(j, graf[i]) {
			if (cycle_id[i] == -1 || cycle_id[j] == -1) hldgraf[i].pb(j);
		}
	}
	
	int NC = sz(cycle);
	HLD<true, S, op, e, bool, mapping, composition, id> hld(hldgraf, cycle);
	lazy_segtree<S, op, e, bool, mapping, composition, id> gorne(vector<S>(NC, e()));
	debug(cycle);
	
	auto toggle_cycle_path = [&](int i, int j, bool right) {
		if (!right) {
			swap(i, j); right = true;
		}
		if (i <= j) {
			gorne.apply(i, j, true);
		}
		else { //we loop over the cycle
			gorne.apply(i, NC, true);
			gorne.apply(0, j, true);
		}
	};
	
	auto toggle_path = [&](int a, int b) {
		if (hld.treeroot[a] == hld.treeroot[b]) { //same tree
			hld.path_apply(a, b, true);
			return;
		}
		hld.path_apply(a, hld.treeroot[a], true);
		hld.path_apply(b, hld.treeroot[b], true);
		a = hld.treeroot[a];
		b = hld.treeroot[b];
		assert(a != b);
		assert(cycle_id[a] != -1); assert(cycle_id[b] != -1);
		
		//now we only need to handle cycle query
		int i = cycle_id[a], j = cycle_id[b];
		assert(i != j);
		int dist_right = j > i ? abs(j - i) : NC - abs(j - i);
		int dist_left = i > j ? abs(j - i) : NC - abs(j - i);
		debug(i, j);
		if (dist_right < dist_left) toggle_cycle_path(i, j, true);
		if (dist_right > dist_left) toggle_cycle_path(i, j, false);
		if (dist_right == dist_left) { //the annoying case
			if (cycle[(i + 1 + NC) % NC] < cycle[(i - 1 + NC) % NC]) {
				toggle_cycle_path(i, j, true);
			}
			else toggle_cycle_path(i, j, false);
		}
	};
	
	auto query_all = [&]() {
		int comps = n;
		S trees = hld.all_prod();
		comps -= trees.ones; //each one decreases n. of components by one
		S above = gorne.all_prod();
		comps -= above.ones;
		//one stupid special case
		if (above.ones == sz(cycle)) comps++;
		return comps;
	};
	
	while (zap--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		toggle_path(a, b);
		cout << query_all() << "\n";
	}
}