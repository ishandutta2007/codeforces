#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> P(n);
	for(int i = 0; i < n; i++) cin >> P[i];
	vector<vector<int> > edges(n);
	vector<vector<int> > bedges(n);
	vector<int> deg(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		bedges[v].push_back(u);
		deg[u]++;
	}
	vector<int> bfs;
	vector<int> hgt(n, -1);
	int s = 0;
	for(int i = 0; i < n; i++){
		if(deg[i] == 0) bfs.push_back(i);
	}
	while(s < bfs.size()){
		int v = bfs[s];
		s++;
		set<int> lvls;
		for(int x : edges[v]){
			lvls.insert(hgt[x]);
		}
		int a = 0;
		while(lvls.count(a)) a++;
		hgt[v] = a;
		for(int y : bedges[v]){
			deg[y]--;
			if(deg[y] == 0) bfs.push_back(y);
		}
	}
	vector<ll> val(n, 0);
	for(int i = 0; i < n; i++){
		assert(hgt[i] != -1);
		val[hgt[i]] ^= P[i];
	}
	int maxv = -1;
	for(int i = 0; i < n; i++){
		if(val[i] > 0) maxv = i;
	}
	if(maxv == -1){
		cout << "LOSE" << '\n';
		exit(0);
	} else {
		cout << "WIN" << '\n';
	}
	vector<int> hh;
	for(int i = 0; i < n; i++){
		if(hgt[i] == maxv) hh.push_back(i);
	}
	ll tot = 0;
	for(int x : hh){
		tot ^= P[x];
	}
	assert(tot == val[maxv]);
	int mv = -1;
	for(int x : hh){
		if((P[x] ^ tot) < P[x]){
			mv = x;
		}
	}
	assert(mv != -1);
	P[mv] = P[mv] ^ tot;
	vector<int> go(n, -1);
	for(int y : edges[mv]){
		go[hgt[y]] = y;
	}
	for(int b = 0; b < maxv; b++){
		P[go[b]] = val[b] ^ P[go[b]];
	}
	for(int i = 0; i < n; i++){
		cout << P[i] << ' ';
	}
	cout << '\n';
}