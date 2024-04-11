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
		ll a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			if(x % 3 == 1) {
				a++;
			}
			else if(x % 3 == 2) {
				b++;
			}
			else {
				c++;
			}
		}
		cout << c + min(a, b) + (a - min(a, b)) / 3 + (b - min(a, b)) / 3 << endl;
	}
}