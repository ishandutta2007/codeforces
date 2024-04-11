#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, sz[100100], par[100100];
vector<int> v[100100];

int dfs(int u, int p){
	sz[u] = 1;
	par[u] = p;
	for(int x : v[u]) if(x != p) sz[u] += dfs(x, u);
	return sz[u];
}

int find(int u){
	int re = 0;
	if(u == 1){
		for(int x : v[u]) re = max(re, sz[x]);
		return re;
	}

	for(int x : v[u]){
		if(x == par[u]){
			re = max(re, n - sz[u]);
		}else{
			re = max(re, sz[x]);
		}
	}
	return re;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=1;i<=n;i++) v[i].clear(), sz[i] = 0;

		for(int i=1;i<n;i++){
			int a, b; cin >> a >> b;
			v[a].push_back(b), v[b].push_back(a);
		}

		dfs(1, 0);

		int mn = 1e9;
		vector<int> ans;
		for(int i=1;i<=n;i++){
			int k = find(i);
			if(k > mn) continue;

			if(k < mn) ans.clear();
			mn = k;
			ans.push_back(i);
		}

		if(ans.size() == 1){
			cout << ans[0] << " " << v[ans[0]][0] << "\n";
			cout << ans[0] << " " << v[ans[0]][0] << "\n";
		}else{
			int fl = (v[ans[0]][0] == ans[1]);
			cout << ans[0] << " " << v[ans[0]][fl] << "\n";
			cout << ans[1] << " " << v[ans[0]][fl] << "\n";
		}
	}
}