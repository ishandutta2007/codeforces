/**
 *    author:  Mohamed.Abo_Okail
 *    created: 28/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		ll ans = n / k;
		ans *= k;
		if(!(n % k)) { cout << ans << endl; }
		else {
			ll cnt = n % k;
			ll x = k / 2;
			ans += min(cnt, x);
			cout << ans << endl;
		}
	}
}