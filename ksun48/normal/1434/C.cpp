#include <bits/stdc++.h>
using namespace std;

void solve(){
	using ll = long long;
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a > b * c){
		cout << -1 << '\n';
		return;
	}
	ll k = a / b / d;
	ll ans = (k+1) * a - k * (k+1) / 2 * b * d;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}