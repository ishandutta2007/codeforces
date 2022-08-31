#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > in_edges(n);
	vector<int> deg(n, 0);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(a > b) swap(a, b);
		in_edges[a].push_back(b);
		deg[a]++;
		deg[b]++;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += ll(in_edges[i].size()) * ll(deg[i] - in_edges[i].size());
	}
	int q;
	cin >> q;
	cout << ans << '\n';
	for(int i = 0; i < q; i++){
		int v;
		cin >> v;
		v--;
		ans -= ll(in_edges[v].size()) * ll(deg[v] - in_edges[v].size());
		for(int x : in_edges[v]){
			ans -= ll(in_edges[x].size()) * ll(deg[x] - in_edges[x].size());
			in_edges[x].push_back(v);
			ans += ll(in_edges[x].size()) * ll(deg[x] - in_edges[x].size());
		}
		in_edges[v].clear();
		cout << ans << '\n';
	}
}