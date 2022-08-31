#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans -= (i - (n-1-i)) * a[i];
	}
	ans += a.back() - a.front();
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}