#include <bits/stdc++.h>
using namespace std;

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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	reverse(s.begin(), s.end());
	vector<int> need_sand(m);
	for(int& x : need_sand) cin >> x;
	vector<int> vis(m, -1);
	vector<int> need(m, -1);
	vector<int> max_sand(m, -1);
	for(int i = 0; i < m; i++){
		int found = 0;
		for(int j = 0; j < n; j++){
			if(s[j][i] == '#'){
				max_sand[i] = max(max_sand[i], j);
			}
		}
		if(need_sand[i] == 0) continue;
		for(int j = 0; j < n; j++){
			if(s[j][i] == '#'){
				found++;
				if(found == need_sand[i]){
					need[i] = j;
					break;
				}
			}
		}
	}
	vector<vector<int> > edges(n*m);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(j-1 >= 0) edges[i*n + j].push_back(i*n + (j-1));
			if(j+1 < n && s[j+1][i] == '#') edges[i*n + j].push_back(i*n + (j+1));
			if(i-1 >= 0 && s[j][i-1] == '#') edges[i*n + j].push_back((i-1)*n + j);
			if(i+1 < m && s[j][i+1] == '#') edges[i*n + j].push_back((i+1)*n + j);
		}
	}
	scc(edges, [&](vector<int> cc){});
	vector<vector<int> > cc(n, vector<int>(m));
	for(int j = 0; j < n; j++){
		for(int i = 0; i < m; i++){
			cc[j][i] = comp[i*n+j];
		}
	}
	auto fill = y_combinator(
		[&](auto self, int i, int h) -> void {
			if(vis[i] < h){
				vis[i]++;
				int r = vis[i];
				if(i > 0 && s[r][i-1] == '#') self(i-1, r);
				if(i+1 < m && s[r][i+1] == '#') self(i+1, r);
				if(r+1 < n && s[r+1][i] == '#') self(i, r+1);
				self(i, h);
			}
		}
	);
	int ans = 0;
	for(int i = 0; i < m; i++){
		if(vis[i] >= need[i]) continue;

		int ci = i;
		int cur = need[i];
		while(true){
			assert(cur <= max_sand[ci]);
			while(cur-1 >= 0 && cc[cur-1][ci] == cc[cur][ci]) cur--;
			while(s[cur][ci] != '#') cur++;
			if(ci + 1 < m){
				int found = -1;
				for(int j = 0; j < n; j++){
					if(s[j][ci+1] == '#' && (cc[j][ci+1] == cc[cur][ci] || j >= cur)){
						found = j;
						break;
					}
				}
				if(found == -1){
					break;
				} else {
					cur = max(found, need[ci+1]);
					ci = ci+1;
				}
			} else {
				break;
			}
		}
		// assert(cur <= max_sand[ci]);
		fill(ci, max_sand[ci]);
		ans++;
	}
	cout << ans << '\n';
}