/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	ll ans = 0;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if(x < 0) {
			ans += (x * -1 - 1);
			a++;
		}
		else if(x > 0) {
			ans += (x - 1);
		}
		else {
			b++;
		}
	}
	if(a % 2) {
		if(b) {
			cout << ans + b << endl;
		}
		else {
			cout << ans + 2 << endl;
		}
	}
	else {
		cout << ans + b << endl;
	}
}