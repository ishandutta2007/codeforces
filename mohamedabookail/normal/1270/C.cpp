/**
 *    author:  Mohamed.Abo_Okail
 *    created: 30/12/2019
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
		ll n; cin >> n;
		ll cnt = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			sum += a;
			cnt ^= a;
		}

		cout << 2 << endl;
		cout << cnt << ' ' << (sum + cnt) << endl;
	}
}