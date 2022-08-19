#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(vector<int>& x : a){
		for(int& y : x){
			cin >> y;
		}
	}
	set<pair<int,int> > freq;
	for(vector<int> x : a){
		vector<int> sx = x;
		sort(sx.begin(), sx.end());
		if(x == sx) continue;
		vector<int> locs;
		for(int i = 0; i < sx.size(); i++){
			if(x[i] != sx[i]) locs.push_back(i);
		}
		assert(!locs.empty());
		if(locs.size() > 2){
			cout << -1 << '\n';
			return;
		}
		assert(locs.size() == 2);
		freq.insert({locs[0], locs[1]});
	}
	if(freq.size() > 1){
		cout << -1 << '\n';
		return;
	}
	if(freq.size() == 0){
		cout << 1 << ' ' << 1 << '\n';
		return;
	}
	auto [x, y] = *freq.begin();
	for(int i = 0; i < n; i++){
		swap(a[i][x], a[i][y]);
		vector<int> sx = a[i];
		sort(sx.begin(), sx.end());
		if(sx != a[i]){
			cout << -1 << '\n';
			return;
		}
	}
	cout << (x+1) << ' ' << (y+1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}