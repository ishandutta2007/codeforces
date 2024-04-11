#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;

vector<vector<pair<int, ll> > > edges;

// no yes

pair<ll, ll> dfs(ll v, ll p, ll up_edge){
	ll tot = 0;
	vector<ll> stuff;
	for(auto r : edges[v]){
		int w = r.first;
		if(w == p) continue;
		pair<ll, ll> q = dfs(w, v, r.second);
		tot += q.first;
		stuff.push_back(q.second - q.first);
	}
	sort(stuff.begin(), stuff.end());
	reverse(stuff.begin(), stuff.end());
	ll use_up = tot + up_edge;
	ll no_use_up = tot;
	for(int i = 0; i < k-1 && i < (int)stuff.size(); i++) use_up += stuff[i];
	for(int i = 0; i < k && i < (int)stuff.size(); i++) no_use_up += stuff[i];
	use_up = max(use_up, no_use_up);
	return {no_use_up, use_up};
}

void solve(){
	cin >> n >> k;
	edges.assign(n, {});
	for(int i = 0; i < n-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}
	pair<ll, ll> best = dfs(0, -1, 0);
	cout << best.second << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> Q;
	for(int _ = 0; _ < Q; _++) solve();
}