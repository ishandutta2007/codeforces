#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	map<int, vector<pair<int,int> > > p;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int a;
			cin >> a;
			p[a].push_back({i, j});
		}
	}
	ll ans = 0;
	for(auto [_, v] : p){
		sort(v.begin(), v.end());
		ll k = v.size();
		for(int i = 0; i + 1 < v.size(); i++){
			ans += (v[i+1].first - v[i].first) * ll(i+1) * ll(k - (i+1));
		}
		sort(v.begin(), v.end(), [&](pair<int,int> a, pair<int,int> b){ return a.second < b.second; });
		for(int i = 0; i + 1 < v.size(); i++){
			ans += (v[i+1].second - v[i].second) * ll(i+1) * ll(k - (i+1));
		}
	}
	cout << ans << '\n';
}