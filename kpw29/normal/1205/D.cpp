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
            if (par[pre[i]] == pre[0]) res.push_back(i);
        }
        res.push_back(sz(pre));
        return res;
    }
    //calculate answers for the current centroid(root). Nodes given in PREORDER
    virtual void calc(int root, vi &nodes) = 0;
    private:
    void prep(int x, vi &nodes) {
        odw[x] = 1; sub[x] = 1;
        nodes.push_back(x);
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

struct centroids : base_centroids {
    centroids(int N, vector <vi> graph) : base_centroids(N, graph) {}
    void calc(int root, vi &nodes) {
		debug(root);
        auto subtree = get_subtrees(nodes);
        vector <pii> ranges;
        rep(i, 0, sz(subtree)-1) ranges.pb({subtree[i + 1] - subtree[i], subtree[i]});
        vi typ(sz(nodes), -1);
        sort(all(ranges));
        vi ile(2, 0);
        for (int xd = sz(ranges)-1; xd >= 0; --xd) {
			auto &[length, start] = ranges[xd];
			debug(length, start);
			int gdzie = 0;
			if (ile[0] < ile[1]) gdzie = 0;
			else gdzie = 1;
			for (int i = 0; i < length; ++i) typ[start + i] = gdzie;
			ile[gdzie] += length;
		}
		
		if (ile[0] < ile[1]) typ[0] = 0, ile[0]++;
		else typ[0] = 1, ile[1]++;
		int N = sz(nodes);
		rep(i, 0, N) assert(typ[i] != -1);
		debug(nodes);
		debug(typ);
		vector <ll> topar(N, 0);
		vector <ll> dist(N, 0);
		
		ll desired = 0; //tyle ma root
        rep(i, 1, N) {
			if (typ[i] == typ[0]) { //ten sam zbior
				desired += 1;
				dist[nodes[i]] = desired;
				topar[nodes[i]] = desired - dist[par[nodes[i]]];
			}
		}
		
		// teraz jeszcze drugi zbior
		desired = 0;
		rep(i, 1, N) {
			if (typ[i] != typ[0]) {
				desired += ile[typ[0]];
				dist[nodes[i]] = desired;
				topar[nodes[i]] = desired - dist[par[nodes[i]]];
			}
		}
		
		// only print the answer
		rep(i, 1, N) {
			assert(topar[nodes[i]] >= 0);
			cout << nodes[i] + 1 << ' ' << par[nodes[i]] + 1 << ' ' << topar[nodes[i]] << "\n";
		}
        exit(0);
    }
};

//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n;
	cin >> n;
	vector<vi> graf(n);
	rep(i, 1, n) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	centroids solver(n, graf);
	solver.solve();
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