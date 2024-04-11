#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;

void get_leaves(int v, int p, vector<int>& s, bool quit = false){
	bool leaf = true;
	for(int w : edges[v]){
		if(w == p) continue;
		leaf = false;
		get_leaves(w, v, s, true);
		if(quit) return;
	}
	if(leaf) s.push_back(v);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n-1), b(n-1), w(n-1);
	vector<int> deg(n, 0);
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		cin >> a[i] >> b[i] >> w[i];
		a[i]--; b[i]--;
		deg[a[i]] += 1;
		deg[b[i]] += 1;
		edges[a[i]].push_back(b[i]);
		edges[b[i]].push_back(a[i]);
	}
	for(int i = 0; i < n; i++){
		if(deg[i] == 2){
			cout << "NO" << '\n';
			return 0;
		}
	}
	vector<vector<int> > ans;
	for(int i = 0; i < n-1; i++){
		int v1 = a[i];
		int v2 = b[i];
		int wgt = w[i];
		if(deg[v1] > deg[v2]) swap(v1, v2);
		if(deg[v1] == 1 && deg[v2] == 1){
			ans.push_back({v1, v2, -wgt});
		} else if(deg[v1] == 1){
			vector<int> s2;
			get_leaves(v2, v1, s2);
			ans.push_back({v1, s2[0], -wgt/2});
			ans.push_back({v1, s2[1], -wgt/2});
			ans.push_back({s2[0], s2[1], wgt/2});
		} else {
			vector<int> s1, s2;
			get_leaves(v1, v2, s1);
			get_leaves(v2, v1, s2);
			ans.push_back({s1[0], s2[0], -wgt/2});
			ans.push_back({s1[1], s2[1], -wgt/2});
			ans.push_back({s1[0], s1[1], wgt/2});
			ans.push_back({s2[0], s2[1], wgt/2});
		}
	}

	cout << "YES" << '\n';
	cout << ans.size() << '\n';
	for(vector<int> r : ans){
		cout << r[0] + 1 << ' ' << r[1] + 1 << ' ' << -r[2] << '\n';
	}
}