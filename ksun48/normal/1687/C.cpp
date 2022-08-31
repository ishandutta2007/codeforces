#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		a[i] += x;
	}
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		a[i] -= x;
	}
	vector<ll> psum(n+1, 0);
	for(int i = 0; i < n; i++){
		psum[i+1] = psum[i] + a[i];
	}
	vector<pair<int,int> > good;
	vector<vector<pair<int,int> > > edges(n+1);
	vector<vector<pair<int,int> > > both_edges(n+1);
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		r++;
		if(psum[l] == 0 && psum[r] == 0){
			good.push_back({l, r});
		} else if(psum[l] == 0){
			edges[r].push_back({l, r});
		} else if(psum[r] == 0){
			edges[l].push_back({l, r});
		} else {
			both_edges[l].push_back({l, r});
			both_edges[r].push_back({l, r});
		}
	}
	for(int i = 0; i < n; i++){
		if(a[i] == 0 && psum[i] == 0){
			good.push_back({i, i+1});
		}
	}
	if(psum.back() != 0){
		cout << "NO" << '\n';
		return;
	}
	vector<int> vis(n+1);
	set<int> unvis;
	for(int i = 0; i < n; i++){
		unvis.insert(i);
	}
	int idx = 0;
	while(idx < (int)good.size()){
		auto [l, r] = good[idx];
		idx++;
		while(true){
			auto x = unvis.lower_bound(l);
			if(x != unvis.end() && (*x < r)){
				int v = *x;
				unvis.erase(x);
				for(int y : {v, v+1}){
					if(!vis[y]){
						vis[y] = 1;
						for(auto [el, er] : edges[y]){
							good.push_back({el, er});
						}
						for(auto [el, er] : both_edges[y]){
							edges[el ^ er ^ y].push_back({el, er});
						}
					}
				}
			} else {
				break;
			}
		}
	}
	bool done = true;
	for(int i = 0; i < n; i++){
		if(a[i] != 0 && unvis.count(i)) done = false;
	}
	if(done){
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}