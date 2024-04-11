#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	ll n, x;
	cin >> n >> x;
	vector<ll> d(n), h(n);
	for(int i = 0; i < n; i++) cin >> d[i] >> h[i];
	vector<ll> diffs;
	ll best = 1e9;
	ll bestone = 0;
	for(int i = 0; i < n; i++){
		best = min(best, h[i] - d[i]);
		bestone = max(bestone, d[i]);
	}
	x -= bestone;
	x = max(x, 0ll);
	if(x == 0){
		cout << 1 << '\n';
	} else if(best < 0){
		cout << 1 + (x + (-best - 1)) / (-best) << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}