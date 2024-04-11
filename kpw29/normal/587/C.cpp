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

template <bool VALS_EDGES,
class S, S(*op)(S, S), S(*e)(),
class F, S (*mapping)(F, S), F(*composition)(F, F), F (*id)()>
struct HLD {
	int N, tim = 0;
	vector <vi> adj;
	vi par, siz, depth, rt, pos;
	lazy_segtree<S, op, e, F, mapping, composition, id> tree;
	HLD(vector <vi> adj_, int root=0) : 
		N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		rt(N,root), pos(N), tree(vector<S>(N, e())) {dfsSz(root), dfsHld(root);}
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		trav(u, adj[v]){
			par[u] = v, depth[u] = depth[v] + 1;
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
};
const int C = 10;
const int inf = 1e9+9;

typedef array<int, 10> arr;

arr e() {return array<int, 10>({inf, inf, inf, inf, inf, inf, inf, inf, inf, inf}); }
arr merge(arr a, arr b) {
	auto res = e();
	int ita = 0, itb = 0;
	rep(i, 0, 10) {
		if (a[ita] < b[itb]) res[i] = (a[ita++]);
		else res[i] = (b[itb++]);
	}
	return res;
}


int main() {
	boost;
	int n, m, q;
	cin >> n >> m >> q;
	vector <vi> graf(n);
	rep(i, 1, n) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	HLD<false, arr, merge, e, arr, merge, merge, e> tree(graf);
	
	rep(i, 1, m+1) {
		int gdzie;
		cin >> gdzie; --gdzie;
		arr tmp = e();
		tmp[0] = i;
		tree.path_apply(gdzie, gdzie, tmp);
	}
	
	while (q--) {
		int a, b, ile;
		cin >> a >> b >> ile;
		--a; --b;
		arr wynik = tree.path_prod(a, b);
		vi vec = {};
		rep(i, 0, ile) if(wynik[i] != inf) vec.pb(wynik[i]);
		
		cout << sz(vec) << ' ';
		trav(elem, vec) cout << elem << ' ';
		cout << "\n";
	}
	
}