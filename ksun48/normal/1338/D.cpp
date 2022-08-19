#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > tree;

vector<int> score;

pair<int,int> dfs(int v, int p, int& ans){
	pair<int,int> m1 = {0, 1}, m2 = {0, 1};
	int nc = 0;
	for(int w : tree[v]){
		if(w == p) continue;
		pair<int,int> z = dfs(w, v, ans);
		if(m2.first) nc++;
		m2 = max(m2, z);
		if(m2 > m1) swap(m1, m2);
	}
	int free = m1.second & m2.second;
	int res = m1.first + m2.first + nc;
	if(nc) free = 0;
	if(v || free) res++;
	ans = max(ans, res);

	int ret = m1.first + nc + min(m2.first, 1);
	if(m2.first) free = 0;
	return {ret + free, 1 ^ free};
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	tree.resize(n);
	score.assign(n, -2);
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
		score[a]++;
		score[b]++;
	}
	int ans = -1e9;
	dfs(0, -1, ans);
	cout << ans << '\n';
}