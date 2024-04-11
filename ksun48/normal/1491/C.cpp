#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	ll	 n;
	cin >> n;
	vector<ll> s(n);
	for(ll& x : s) cin >> x;
	ll worst = 0;
	for(ll i = 0; i < n; i++){
		ll cost = 0;
		for(ll j = 0; j <= i; j++){
			cost += max(0ll, s[j]-max(1ll, i-j));
		}
		worst = max(worst, cost);
	}
	cout << worst << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}