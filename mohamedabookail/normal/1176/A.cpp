/**
 *    author:  Mohamed.Abo_Okail
 *    created: 31/12/2019
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
		ll ans = 0;
		while(n > 1) {
			if(!(n % 2)) {
				n /= 2;
				ans++;
			}
			else if(!(n % 3)) {
				n -= n / 3;
				ans++;
			}
			else if(!(n % 5)) {
				n -= n / 5;
				ans++;
			}
			else {
				break;
			}
		}

		if(n == 1) {
			cout << ans << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}