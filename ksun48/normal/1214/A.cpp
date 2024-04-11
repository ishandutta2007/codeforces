#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll n, d, e;
	cin >> n >> d >> e;
	e *= 5;
	ll ans = n;
	for(ll g = 0; g <= 1000; g++){
		if(n >= g * d){
			ans = min(ans, (n - g * d) % e);
		}
	}
	cout << ans << '\n';
}