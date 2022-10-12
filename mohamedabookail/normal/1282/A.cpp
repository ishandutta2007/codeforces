/**
 *    author:  Mohamed.Abo_Okail
 *    created: 25/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll x = (c - d), y = (c + d);
		if(a < b) swap(a, b);
		if(x < y) swap(x, y);
		if(y >= a || x <= b) {
			cout << (a - b) << endl;
		}
		else {
			cout << max((a - x), 0ll) + max((y - b), 0ll) << endl;
		}
	}
	
}