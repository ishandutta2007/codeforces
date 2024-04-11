#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;

int ans;

int dfs(int v, int p){
	vector<int> s = {0, 0};
	for(int w : edges[v]){
		if(w == p) continue;
		int r = dfs(w, v);
		s.push_back(r);
	}
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	ans = max(ans, s[0] + s[1] + (int)edges[v].size() + 1);
	return s[0] + (int)edges[v].size() - 1;
}

void solve(){
	int n;
	cin >> n;
	edges.assign(n, {});
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	ans = 0;
	dfs(0, -1);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int _ = 0; _ < T; _++){
		solve();
	}
}