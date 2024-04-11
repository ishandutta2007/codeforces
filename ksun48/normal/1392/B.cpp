#include <bits/stdc++.h>
using namespace std;


void solve(){
	using ll = long long;
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	k = ((k-1) % 2) + 1;
	for(ll& x : a) cin >> x;
	for(int j = 0; j < k; j++){
		ll maxval = -1e18;
		for(ll& x : a) maxval = max(maxval, x);
		for(ll& x : a) x = maxval - x;
	}
	for(ll x : a) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}