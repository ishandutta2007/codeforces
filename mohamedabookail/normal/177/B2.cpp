/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	ll ans = (n + 1);
	while(n) {
		ll c = n;
		for (int i = 2; (i * i) <= n; i++) {
			if(!(n % i)) {
				n /= i;
				if(n == 1) { n = 0; }
				ans += n;
				break;
			}
		}
		if(c == n) { break; }
	}
	cout << ans << endl;
}