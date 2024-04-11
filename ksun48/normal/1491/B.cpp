#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	int n;
	ll u, v;
	cin >> n >> u >> v;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	bool same = true;
	for(int x : a){
		if(x != a.front()) same = false;
	}
	int cost = 1e9;
	for(int i = 1; i < n; i++){
		if(abs(a[i] - a[i-1]) > 1){
			cout << 0 << '\n';
			return;
		}
	}
	if(same){
		cout << v + min(u, v) << '\n';
	} else {
		cout << min(u, v) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}