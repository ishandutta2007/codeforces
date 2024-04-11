#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	ll ans = 0;

	ll l = min(k, n);
	vector<ll> psums(n+1);
	for(int i = 0; i < n; i++){
		psums[i+1] = psums[i] + a[i];
	}
	for(int i = 0; i + l <= n; i++){
		ll x = psums[i+l] - psums[i];
		ll extras = l * k - l * (l+1) / 2;
		ans = max(ans, x + extras);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}