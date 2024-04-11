#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	int n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0;
	ll cmin = 2e9;
	ll cmax = -2e9;
	for(int i = 0; i < n; i++){
		cmin = min(cmin, a[i]);
		cmax = max(cmax, a[i]);
		if(cmax - cmin > 2 * x){
			ans++;
			cmin = cmax = a[i];
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}