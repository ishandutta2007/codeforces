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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	vector<int> freq(n+1, 0);
	for(int x : a) freq[x]++;
	int mf = 0;
	for(int i = 0; i <= n; i++) if(freq[i] > freq[mf]) mf = i;
	vector<vector<int> > graph(n+1);
	int cyc = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == mf || b[i] == mf) continue;
		graph[a[i]].push_back(b[i]);
		if(a[i] == b[i]) cyc = 1;
	}
	scc(graph, [&](vector<int> cc){
		if(cc.size() >= 2) cyc = 1;
	});
	if(cyc){
		cout << "WA" << '\n';
	} else {
		cout << "AC" << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}