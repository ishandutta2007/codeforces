#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		trav(y, C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
};

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<vector<int> > ch(n);
	vector<int> s(n);
	vector<int> par(n);
	vector<int> dist(n);
	y_combinator(
		[&](auto self, int v, int p, int d) -> void {
			par[v] = p;
			s[v] = 1;
			dist[v] = d;
			for(int w : edges[v]){
				if(w == p) continue;
				self(w, v, d+1);
				ch[v].push_back(w);
				s[v] += s[w];
			}
		}
	)(0, -1, 0);
	const int MAXJ = 20;
	vector<vector<int> > jump(MAXJ, vector<int>(n));
	jump[0] = par;
	jump[0][0] = 0;
	for(int j = 1; j < MAXJ; j++){
		for(int i = 0; i < n; i++){
			jump[j][i] = jump[j-1][jump[j-1][i]];
		}
	}
	LCA lca(edges);
	auto d = [&](int u, int v) -> int {
		return dist[u] + dist[v] - 2 * dist[lca.lca(u, v)];
	};
	auto up = [&](int u, int b) -> int {
		for(int j = MAXJ-1; j >= 0; j--){
			if(b & (1 << j)){
				u = jump[j][u];
			}
		}
		return u;
	};
	vector<ll> cnts(n+1, 0);
	cnts[0] = 1ll * n * (n-1) / 2;
	int u = -1, v = -1;
	for(int i = 0; i < n; i++){
		if(u == -1 && v == -1){
			u = v = i;
		} else {
			int f = d(u, i);
			int g = d(v, i);
			int h = d(u, v);
			if(f + g == h){
			} else if(f + h == g){
				u = i;
			} else if(g + h == f){
				v = i;
			} else {
				break;
			}
		}
		if(u == v){
			cnts[i+1] = 1ll * n * (n-1) / 2;
			int tot = n-1;
			for(int x : ch[u]){
				cnts[i+1] -= 1ll * s[x] * (s[x]-1) / 2;
				tot -= s[x];
			}
			cnts[i+1] -= 1ll * tot * (tot-1) / 2;
		} else {
			int w = lca.lca(u, v);
			if(v == w) swap(u, v);
			if(u == w){
				int c = up(v, dist[v] - dist[u] - 1);
				assert(par[c] == u);
				cnts[i+1] = 1ll * s[v] * (n - s[c]);
			} else {
				cnts[i+1] = 1ll * s[u] * s[v];
			}
		}
	}
	for(int i = 0; i <= n; i++){
		if(i < n){
			cnts[i] -= cnts[i+1];
		}
		cout << cnts[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}