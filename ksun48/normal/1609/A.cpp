#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	int k = 0;
	for(ll& x : a){
		cin >> x;
		while(x % 2 == 0){
			x /= 2;
			k += 1;
		}
	}
	sort(a.rbegin(), a.rend());
	a[0] *= (1ll << k);
	ll ans = 0;
	for(ll x : a) ans += x;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}