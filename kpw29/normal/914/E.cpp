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
const int maxn = 200100;

int waga[maxn];
int cnt_masks[(1 << 21) + 1];

ll wyn[maxn];
ll dp[maxn];

// override calc() to do what you need
// node indexes are preserved throughout invocations
// if something is protected, it is safe to use it in calc()
struct base_centroids {
	private:
	int n; //graph size
	vector <vi> v; //0-based
	vector <bool> odw, gold;
	vi sub, maxsub;
	protected:
	vi par; //current array of nodes'parents. par[root]= -1.
	vi get_subtrees(vi &pre) { //helper fn which finds ranges [, ) of root's subtrees. 
		vi res = {};
		rep(i, 0, sz(pre)) {
			if (par[pre[i]] == pre[0]) res.pb(i);
		}
		res.pb(sz(pre));
		return res;
	}
	//calculate answers for the current centroid(root). Nodes given in PREORDER
	virtual void calc(int root, vi &nodes) = 0;
	private:
	void prep(int x, vi &nodes) {
		odw[x] = 1; sub[x] = 1;
		nodes.pb(x);
		trav(u, v[x]) {
			if (!gold[u] && !odw[u]) {
				prep(u, nodes);
				sub[x] += sub[u];
				maxsub[x] = max(maxsub[x], sub[u]);
			}
		}
	}
	void cendfs(int x, int &PRE, vi &pre) {
		odw[x] = 1; pre[PRE++] = x;
		trav(u, v[x]) {
			if (!odw[u] && !gold[u]) {
				par[u] = x;
				cendfs(u, PRE, pre);
			}
		}
	}
	public:
	base_centroids(int N, vector <vi> graph) : n(N), v(graph), odw(n, false), gold(n, false), sub(n, 0), maxsub(n, 0), par(n, -1) {
	};
	void solve(int start=0) {
		vector <int> comp;
		prep(start, comp);
		int N = sz(comp), cen = -1;
		trav(node, comp) {
			maxsub[node] = max(maxsub[node], N - sub[node]);
			if (maxsub[node] <= N / 2) cen = node;
			odw[node] = 0, sub[node] = 0, maxsub[node] = 0;
		}
		int PRE = 0; 
		vi pre(N, 0);
		par[cen] = -1;
		cendfs(cen, PRE, pre);
		calc(cen, pre);
		trav(node, comp) odw[node] = 0, par[node] = -1;
		gold[cen] = 1;
		trav(u, v[cen]) {
			if (!gold[u]) solve(u);
		}
	}
};

int bitmask[maxn];
ll to_root[maxn];

bool ok(int mask) {
	return __builtin_popcount(mask) <= 1;
}

struct centroids : base_centroids {
	centroids(int N, vector <vi> graph) : base_centroids(N, graph) {}
	void calc(int root, vi &nodes) {
		debug(root);
		debug(nodes);
		auto subtree = get_subtrees(nodes);
		debug(subtree);
		
		bitmask[root] = (1 << waga[root]);
		debug(root, bitmask[root]);
		to_root[root]++;
		rep(i, 1, sz(nodes)) {
			int node = nodes[i];
			bitmask[node] = (1 << waga[node]) ^ (bitmask[par[node]]);
			cnt_masks[bitmask[node]]++;
			if (ok(bitmask[node])) to_root[node]++;
			debug(node, bitmask[node]);
		}
		
		rep(i, 0, sz(subtree)-1) {
			int a = subtree[i], b = subtree[i + 1];
			rep(j, a, b) cnt_masks[bitmask[nodes[j]]]--; //removing this cnt
			
			// asking a query
			rep(j, a, b) {
				int node = nodes[j];
				dp[node] += cnt_masks[bitmask[node] ^ bitmask[root]];
				rep(bit, 0, 20) dp[node] += cnt_masks[bitmask[node] ^ bitmask[root] ^ (1 << bit)];
			}
			
			rep(j, a, b) cnt_masks[bitmask[nodes[j]]]++; //adding back
		}
		
		for (int i=sz(nodes)-1; i>0; --i) {
			int node = nodes[i];
			dp[par[node]] += dp[node];
			to_root[par[node]] += to_root[node];
		}

		trav(node, nodes) {
			debug(node, dp[node]);
			if (node != root) wyn[node] += dp[node];
			else {
				assert(dp[node] % 2 == 0);
				wyn[node] += dp[node] / 2;
			}
			wyn[node] += to_root[node];
			to_root[node] = 0;
			dp[node] = 0;
			cnt_masks[bitmask[node]] = 0;
			bitmask[node] = 0;
		}
	}
};


int main() {
	boost;
	int n;
	cin >> n;
	vector <vi> v(n);
	rep(i, 1, n) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		v[a].pb(b);
		v[b].pb(a);
	}
	rep(i, 0, n) {
		char zn;
		cin >> zn;
		waga[i] = zn-'a';
	}
	
	centroids cd(n, v);
	cd.solve();
	rep(i, 0, n) cout << wyn[i] << ' ';
}