#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n;
	cin >> n;
	ll ans = n;
	for(ll b = 1; b <= n; b *= 10){
		ans = n - b;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}