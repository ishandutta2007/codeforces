#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	ll traps = n-k;
	ll saved = traps * (traps - 1) / 2;
	for(ll i = 0; i < n; i++){
		a[i] += i;
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i = 0; i < traps; i++){
		ans += a[i];
	}
	ans -= saved;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}