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

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > gr(n);
	vector<vector<pair<int, ll> > > edges(n);
	for(int i = 0; i < m; i++){
		int a, b, l;
		cin >> a >> b >> l;
		a--; b--;
		gr[a].push_back(b);
		edges[a].push_back({b, l});
	}
	scc(gr, [](vi x){});
	vector<ll> gcds(ncomps, 0);
	vector<int> vis(n, 0);
	vector<ll> dist(n, -1);
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			y_combinator(
				[&](auto self, int v, ll depth) -> void {
					vis[v] = 1;
					dist[v] = depth;
					for(auto [w, d] : edges[v]){
						if(vis[w]){
							if(comp[v] == comp[w]){
								gcds[comp[v]] = gcd(gcds[comp[v]], d + dist[v] - dist[w]);
							}
						} else {
							self(w, depth + d);
						}
					}
				}
			)(i, 0);
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int v;
		ll s, t;
		cin >> v >> s >> t;
		v--;
		t = gcd(t, gcds[comp[v]]);
		bool ans = (s == 0 || (t != 0 && (s % t == 0)));
		cout << (ans ? "YES" : "NO") << '\n';
	}
}