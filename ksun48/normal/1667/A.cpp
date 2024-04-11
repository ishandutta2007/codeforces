#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a){
		cin >> x;
	}
	ll ans = 1e18;
	for(int i = 0; i < n; i++){
		ll moves = 0;
		ll v = 0;
		for(int j = i+1; j < n; j++){
			ll d = a[j];
			ll x = v / d + 1;
			v = x * d;
			moves += x;
		}
		v = 0;
		for(int j = i-1; j >= 0; j--){
			ll d = a[j];
			ll x = v / d + 1;
			v = x * d;
			moves += x;
		}
		ans = min(ans, moves);
	}
	cout << ans << '\n';
}