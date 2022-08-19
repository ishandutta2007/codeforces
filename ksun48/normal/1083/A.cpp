#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> w;
vector<vector<pair<int,LL> > > edges;
LL ans = 0;
LL best(LL v, LL p){
	vector<LL> f = {0, 0};
	for(int i = 0; i < edges[v].size(); i++){
		if(edges[v][i].first == p) continue;
		LL cost = - edges[v][i].second + best(edges[v][i].first, v);
		f.push_back(cost);
	}
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	ans = max(w[v] + f[0] + f[1], ans);
	return w[v] + f[0];
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	w.resize(n);
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		LL c;
		cin >> u >> v >> c;
		u--; v--;
		edges[u].push_back({v,c});
		edges[v].push_back({u,c});
	}
	best(0, -1);
	cout << ans << '\n';
}