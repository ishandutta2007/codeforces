#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(k);
	for(ll& x : a) cin >> x;
	bool ans = false;
	for(ll x : a){
		if(x >= n * m) ans = true;
	}
	for(ll r : {n, m}){
		ll f = 0;
		bool twos_only = true;
		for(ll y : a){
			if(y >= 2 * r) f += y / r;
			if(y >= 3 * r) twos_only = false;
		}
		ll rows = n * m / r;
		if(twos_only && (rows & 1)) continue;
		if(f >= rows) ans = true;
	}
	cout << (ans ? "Yes" : "No") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}