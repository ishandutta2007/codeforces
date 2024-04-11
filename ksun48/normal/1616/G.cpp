#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n, m;
	cin >> n >> m;
	n += 2;
	vector<pair<int,int> > edges;
	for(int i = 1; i < n-1; i++){
		edges.push_back({0, i});
		edges.push_back({i, n-1});
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edges.push_back({a, b});
	}
	vector<int> occ(n-1, 0);
	for(auto [a, b] : edges){
		if(b == a+1){
			occ[a] = 1;
		}
	}
	if(occ == vector<int>(n-1, 1)){
		cout << (ll(n-2) * ll(n-3) / 2) << '\n';
		return;
	}
	vector<int> bad;
	for(int i = 0; i < n-1; i++){
		if(!occ[i]) bad.push_back(i);
	}
	assert(!bad.empty());
	vector<int> lc(4, 0);
	{
		sort(edges.begin(), edges.end());
		reverse(edges.begin(), edges.end());
		vector<vector<int> > reach(n, vector<int>(2, 0));
		reach[bad.front()][0] = 1;
		for(auto [a, b] : edges){
			if(a+1 == b) continue;
			reach[a][1] |= reach[b-1][0];
			reach[a][0] |= reach[b-1][1];
		}
		for(int i = 0; i < n-1; i++){
			lc[(reach[i][1] << 1) ^ (reach[i][0] << 0)]++;
		}
	}
	vector<int> rc(4, 0);
	{
		reverse(edges.begin(), edges.end());
		vector<vector<int> > reach(n, vector<int>(2, 0));
		reach[bad.back()][0] = 1;
		for(auto [a, b] : edges){
			if(a+1 == b) continue;
			reach[b-1][1] |= reach[a][0];
			reach[b-1][0] |= reach[a][1];
		}
		for(int i = 0; i < n-1; i++){
			rc[(reach[i][1] << 1) ^ (reach[i][0] << 0)]++;
		}
	}
	int mid_okay = 0;
	{
		vector<vector<int> > reach(n, vector<int>(2, 0));
		reach[bad.front()][0] = 1;
		for(auto [a, b] : edges){
			if(a+1 == b) continue;
			auto x = lower_bound(bad.begin(), bad.end(), a+1);
			if(x < bad.end() && b > (*x) + 1){
				continue;
			}
			reach[b-1][1] |= reach[a][0];
			reach[b-1][0] |= reach[a][1];
		}
		mid_okay = (reach[bad.back()][1] << 1) ^ (reach[bad.back()][0] << 0);
	}

	ll ans = 0;
	for(int lx = 1; lx < 4; lx++){
		for(int rx = 1; rx < 4; rx++){
			int ok = 0;
			for(int r = 0; r < 2; r++){
				for(int s = 0; s < 2; s++){
					if(1 & (lx >> r) & (rx >> s) & (mid_okay >> (r ^ s))){
						ok = 1;
					}
				}
			}
			if(ok){
				ans += ll(lc[lx]) * ll(rc[rx]);
			}
		}
	}
	if(bad.size() == 1) ans -= 1;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}