#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	ll x;
	cin >> x;
	if(x % 2050 != 0){
		cout << -1 << '\n';
	} else {
		x /= 2050;
		ll ans = 0;
		while(x){
			ans += x % 10;
			x /= 10;
		}
		cout << ans << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}