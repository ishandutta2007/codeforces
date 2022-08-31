#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	using ll = long long;
	int n, m;
	cin >> n >> m;
	vector<ll> w(n);
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	vector<set<int> > edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].insert(v);
		edges[v].insert(u);
	}
	int s;
	cin >> s;
	s--;
	vector<int> deg(n, 0);
	deg[s] = 5;
	vector<int> d1;
	for(int i = 0; i < n; i++){
		deg[i] += (int)edges[i].size();
		if(deg[i] == 1) d1.push_back(i);
	}
	vector<int> par(n, -1);

	ll removed_weight = 0;
	ll total_weight = 0;
	for(int i = 0; i < n; i++) total_weight += w[i];

	int st = 0;
	while(st < d1.size()){
		int a = d1[st];
		st++;
		int b = *edges[a].begin();
		edges[a].erase(b);
		edges[b].erase(a);
		par[a] = b;
		removed_weight += w[a];
		deg[b]--;
		if(deg[b] == 1) d1.push_back(b);
	}
	reverse(d1.begin(), d1.end());
	ll max_leaf = 0;
	vector<ll> dd(n, 0);
	for(int v : d1){
		dd[v] = dd[par[v]] + w[v];
		max_leaf = max(max_leaf, dd[v]);
	}
	ll ans = total_weight - removed_weight + max_leaf;
	cout << ans << '\n';
}