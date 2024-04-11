#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pair<int,int> > eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
	vector<pair<int,int> > ret, s = {{src, -1}};
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x, eid;
		tie(x, eid) = s.back();
		int y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back({x, eid}); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int m;
	cin >> m;
	vector<int> runs;
	vector<pair<int,int> > pairs;
	vector<int> els;
	for(int i = 0; i < m; i++){
		int k;
		cin >> k;
		runs.push_back(k / 2);
		for(int j = 0; j < k/2; j++){
			int a, b;
			cin >> a >> b;
			pairs.push_back({a, b});
			els.push_back(a);
			els.push_back(b);
		}
	}
	sort(els.begin(), els.end());
	for(auto& [x, y] : pairs){
		x = lower_bound(els.begin(), els.end(), x) - els.begin();
		y = lower_bound(els.begin(), els.end(), y) - els.begin();
	}
	int P = pairs.size();
	int K = els.size();
	vector<vector<pii>> gr(K+1);
	for(int i = 0; i < K; i++){
		gr[i].push_back({K, P + i});
		gr[K].push_back({i, P + i});
		gr[i].push_back({K, P + K + i});
		gr[K].push_back({i, P + K + i});
	}
	for(int p = 0; p < pairs.size(); p++){
		auto [x, y] = pairs[p];
		gr[x].push_back({y, p});
		gr[y].push_back({x, p});
	}
	vector<pair<int,int> > walk = eulerWalk(gr, P + 2 * K, 0);
	if(walk.empty()){
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	vector<int> dir(P, -1);
	for(int i = 1; i < walk.size(); i++){
		int x = walk[i-1].first;
		int y = walk[i].first;
		int p = walk[i].second;
		if(p >= P) continue;
		if(pairs[p].first == x && pairs[p].second == y){
			dir[p] = 0;
		} else if(pairs[p].first == y && pairs[p].second == x){
			dir[p] = 1;
		} else assert(false);
	}
	int cur = 0;
	for(int k : runs){
		while(k--){
			cout << (dir[cur] ? "RL" : "LR");
			cur++;
		}
		cout << '\n';
	}
}