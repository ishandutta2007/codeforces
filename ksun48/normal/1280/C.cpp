#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<pair<int,ll> > > edges;

ll a1, a2;
int n;

int dfs(int v, int p){
	int sz = 1;
	for(pair<int,ll> e : edges[v]){
		if(e.first == p) continue;
		int csz = dfs(e.first, v);
		sz += csz;
		if(csz & 1){
			a1 += e.second;
		}
		a2 += e.second * min(n - csz, csz);
	}
	return sz;
}
void solve(){
	a1 = a2 = 0;
	cin >> n;
	n *= 2;
	edges.assign(n, {});
	for(int i = 0; i < n-1; i++){
		int a, b;
		ll t;
		cin >> a >> b >> t;
		a--; b--;
		edges[a].push_back({b, t});
		edges[b].push_back({a, t});
	}
	dfs(0, -1);
	cout << a1 << ' ' << a2 << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}