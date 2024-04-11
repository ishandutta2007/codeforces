#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	int n;
	ll W;
	cin >> n >> W;
	vector<ll> w(n);
	for(ll& x : w) cin >> x;
	for(int i = 0; i < n; i++){
		if(w[i] <= W && w[i] * 2 >= W){
			cout << 1 << '\n';
			cout << (i+1) << '\n';
			return;
		}
	}
	ll tw = 0;
	vector<int> used;
	for(int a = 0; a < n; a++){
		if(tw + w[a] <= W){
			tw += w[a];
			used.push_back(a);
		}
	}
	if(tw * 2 >= W){
		cout << used.size() << '\n';
		for(int r : used){
			cout << r+1 << ' ';
		}
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}