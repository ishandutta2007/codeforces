#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;

vector<int> par;
vector<int> sz;

int cent = -1;

void dfs(int v, int p){
	sz[v] = 1;
	for(int w : edges[v]){
		if(w == p) continue;
		dfs(w, v);
		sz[v] += sz[w];
	}
	if(cent == -1 && sz[v] * 2 >= (int)edges.size()){
		cent = v;
	}
}

void dfs2(int v, int p, vector<int>& ss){
	par[v] = p;
	ss.push_back(v);
	for(int w : edges[v]){
		if(w == p) continue;
		dfs2(w, v, ss);
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	edges.resize(n); par.resize(n); sz.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, -1);
	assert(cent != -1);
	int thresh = 2 * n * n / 9 + 1;
	int s = 0;
	while((s+1) * (n-s) < thresh) s += 1;
	vector<vector<int> > subtrees;
	for(int v : edges[cent]){
		vector<int> x;
		dfs2(v, cent, x);
		subtrees.push_back(x);
	}
	par[cent] = -1;
	vector<pair<int,int> > sizes;
	for(int i = 0; i < subtrees.size(); i++){
		sizes.push_back({subtrees[i].size(), i});
	}
	sort(sizes.begin(), sizes.end());
	reverse(sizes.begin(), sizes.end());
	vector<int> cmp1;
	vector<int> cmp2;
	for(auto r : sizes){
		int a = r.second;
		vector<int>& x = (cmp1.size() < cmp2.size()) ? cmp1 : cmp2;
		for(int v : subtrees[a]){
			x.push_back(v);
		}
	}
	assert((int)cmp1.size() >= s && (int)cmp2.size() >= s);

	long long B = (long long)cmp1.size() + 1;

	vector<long long> wgt(n, 0);
	long long counter = 0;
	for(int a : cmp1){
		counter += 1;
		wgt[a] = counter;
	}
	counter = 0;
	for(int a : cmp2){
		counter += 1;
		wgt[a] = counter * B;
	}
	for(int i = 0; i < n; i++){
		if(i != cent){
			assert(wgt[i] >= wgt[par[i]]);
			cout << i+1 << " " << par[i]+1 << " " << min(1000000ll, wgt[i] - wgt[par[i]]) << '\n';
		}
	}
}