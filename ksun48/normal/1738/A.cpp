#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int& x : a) cin >> x;
	vector<int> b(N);
	for(int& x : b) cin >> x;
	using ll = int64_t;
	ll ans = 0;
	for(int x : b) ans += x;
	vector<vector<ll> > which(2);
	for(int i = 0; i < N; i++){
		which[a[i]].push_back(b[i]);
	}
	for(int j = 0; j < 2; j++){
		sort(which[j].rbegin(), which[j].rend());
	}
	if(which[0].size() == which[1].size()){
		for(int x : b) ans += x;
		ans -= min(which[0].back(), which[1].back());
	} else {
		for(int i = 0; i < min(which[0].size(), which[1].size()); i++){
			ans += which[0][i] + which[1][i];
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