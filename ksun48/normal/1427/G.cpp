#include <bits/stdc++.h>
using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// struct Dinic {
// 	struct Edge {
// 		int to, rev;
// 		ll c, oc;
// 		ll flow() { return max(oc - c, 0LL); } // if you need flows
// 	};
// 	vi lvl, ptr, q;
// 	vector<vector<Edge>> adj;
// 	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
// 	void addEdge(int a, int b, ll c, int rcap = 0) {
// 		adj[a].push_back({b, sz(adj[b]), c, c});
// 		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
// 	}
// 	ll dfs(int v, int t, ll f) {
// 		if (v == t || !f) return f;
// 		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
// 			Edge& e = adj[v][i];
// 			if (lvl[e.to] == lvl[v] + 1)
// 				if (ll p = dfs(e.to, t, min(f, e.c))) {
// 					e.c -= p, adj[e.to][e.rev].c += p;
// 					return p;
// 				}
// 		}
// 		return 0;
// 	}
// 	ll calc(int s, int t) {
// 		ll flow = 0; q[0] = s;
// 		rep(L,0,31) do { // 'int L=30' maybe faster for random data
// 			lvl = ptr = vi(sz(q));
// 			int qi = 0, qe = lvl[s] = 1;
// 			while (qi < qe && !lvl[t]) {
// 				int v = q[qi++];
// 				trav(e, adj[v])
// 					if (!lvl[e.to] && e.c >> (30 - L))
// 						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
// 			}
// 			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
// 		} while (lvl[t]);
// 		return flow;
// 	}
// 	bool leftOfMinCut(int a) { return lvl[a] != 0; }
// };

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int> > A(n, vector<int>(n));
	vector<int> vals;
	vector<pair<int,int> > unknown;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> A[i][j];
			if(A[i][j] > 0) vals.push_back(A[i][j]);
			if(A[i][j] == 0) unknown.push_back({i, j});
		}
	}
	vector<vector<int> > ans = A;
	vals.push_back(1);
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(ans[i][j] == 0) ans[i][j] = 1;
		}
	}
	y_combinator(
		[&](auto self, int l, int r, vector<pair<int,int> > cur) -> void {
			if(l == r){
				return;
			}
			set<pair<int,int> > curset(cur.begin(), cur.end());
			int m = (l + r) / 2;
			set<pair<int,int> > care;
			auto add = [&](int a, int b){
				if(a >= 0 && b >= 0 && a < n && b < n && A[a][b] != -1){
					care.insert({a, b});
				}
			};
			for(pair<int,int> p : cur){
				add(p.first, p.second);
				add(p.first+1, p.second);
				add(p.first-1, p.second);
				add(p.first, p.second+1);
				add(p.first, p.second-1);
			}
			map<pair<int,int>, int> idx;
			for(pair<int,int> v : care){
				int k = (int)idx.size();
				idx[v] = k;
			}
			int k = (int)idx.size();
			PushRelabel mf(k + 2);
			for(pair<int,int> p : care){
				if(curset.count(p)){
					// unknown
					assert(ans[p.first][p.second] == vals[l]);
				} else if(ans[p.first][p.second] <= vals[m]){
					mf.addEdge(k, idx[p], 1e6);
				} else if(ans[p.first][p.second] > vals[m]){
					mf.addEdge(idx[p], k+1, 1e6);
				} else {
					assert(false);
				}
			}
			for(pair<int,int> p : care){
				if(care.count({p.first + 1, p.second})){
					mf.addEdge(idx[p], idx[{p.first + 1, p.second}], 1);
					mf.addEdge(idx[{p.first + 1, p.second}], idx[p], 1);
				}				
				if(care.count({p.first, p.second + 1})){
					mf.addEdge(idx[p], idx[{p.first, p.second + 1}], 1);
					mf.addEdge(idx[{p.first, p.second + 1}], idx[p], 1);
				}
			}
			ll flow = mf.calc(k, k+1);
			vector<pair<int,int> > cur1, cur2;
			for(pair<int,int> p : cur){
				int i = idx[p];
				if(mf.leftOfMinCut(i)){
					cur1.push_back(p);
					ans[p.first][p.second] = vals[l];
				} else {
					cur2.push_back(p);
					ans[p.first][p.second] = vals[m+1];
				}
			}
			self(l, m, cur1);
			self(m+1, r, cur2);
		}
	)(0, (int)vals.size() - 1, unknown);
	ll tot = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			assert(ans[i][j] != 0);
			if(j > 0 && ans[i][j] > 0 && ans[i][j-1] > 0) tot += abs(ans[i][j] - ans[i][j-1]);
			if(i > 0 && ans[i][j] > 0 && ans[i-1][j] > 0) tot += abs(ans[i][j] - ans[i-1][j]);
		}
	}
	cout << tot << '\n';
}