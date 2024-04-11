#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	map<int, vector<int> > where;
	for(int i = 0; i < n; i++){
		where[a[i]].push_back(i);
	}
	vector<int> ans(n+1, 1e8);
	for(auto g : where){
		vector<int> loc = g.second;
		int minl = 0;
		minl = max(minl, loc.front() + 1);
		minl = max(minl, n - loc.back());
		for(int r = 0; r + 1 < (int)loc.size(); r++){
			minl = max(minl, loc[r+1] - loc[r]);
		}
		ans[minl] = min(ans[minl], g.first);
	}
	for(int i = 0; i < n; i++){
		ans[i+1] = min(ans[i+1], ans[i]);
	}
	for(int i = 1; i <= n; i++){
		if(ans[i] > n){
			ans[i] = -1;
		}
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}