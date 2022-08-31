#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	ll n;
	cin >> n;
	ll ans = 0;
	while(n > 0){
		ans += n;
		n /= 2;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll T;
	cin >> T;
	while(T--) solve();
}