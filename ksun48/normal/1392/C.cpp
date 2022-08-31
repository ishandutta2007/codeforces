#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll maxdiff = 0;
	ll sumdiff = 0;
	for(int i = 1; i < n; i++){
		ll f = max(a[i-1] - a[i], 0ll);
		maxdiff += f;
		sumdiff += f;
	}
	cout << max(maxdiff, (sumdiff + 1) / 2) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}