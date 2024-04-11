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
template<class G, class F> int dfs(int j, G& g, F f) {
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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(a == b) continue;
		graph[a].push_back(b);
	}
	vector<vector<int> > sccs;
	scc(graph, [&](const vector<int>& c){
		sccs.push_back(c);
	});
	if(sccs.size() == 1){
		cout << "No" << '\n';
	} else {
		vector<int> ok(n, 0);
		for(int a : sccs.front()) ok[a] = 1;
		cout << "Yes" << '\n';
		cout << sccs.front().size() << ' ' << n - (int)sccs.front().size() << '\n';
		for(int i = 0; i < n; i++){
			if(ok[i]) cout << i + 1 << ' ';
		}
		cout << '\n';
		for(int i = 0; i < n; i++){
			if(!ok[i]) cout << i + 1 << ' ';
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}