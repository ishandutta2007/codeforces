#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int, vector<int> > locs;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		locs[x].push_back(i);
	}
	using ll = int64_t;

	ll ans = 0;
	for(auto r : locs){
		ll psum = 0;
		for(int x : r.second){
			ans += psum * (n-x);
			psum += (x + 1);
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}