#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(auto& x : a) for(int& y : x) cin >> y;
	vector<int> ev;
	vector<pair<int,int> > inds;
	for(int i = 0; i < n; i++){
		sort(a[i].begin(), a[i].end());
		for(int j = 0; j < m; j++) inds.push_back({i, j});
	}
	sort(inds.begin(), inds.end(), [&](pair<int,int> x, pair<int,int> y){
		return a[x.first][x.second] < a[y.first][y.second];
	});
	vector<int> freq(n, 0);
	for(int j = 0; j < m; j++){
		freq[inds[j].first]++;
	}
	vector<int> off(n, 0);
	int cur = 0;
	for(int i = 0; i < n; i++){
		off[i] = cur;
		cur += freq[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][(m - off[i] + j) % m] << ' ';
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}