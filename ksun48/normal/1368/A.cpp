#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll ans = 0;
	while(a <= n && b <= n){
		if(a < b) swap(a, b);
		b += a;
		ans++;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}