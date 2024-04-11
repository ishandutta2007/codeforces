/**
*    author:  Mohamed Abo Okail
*    created: 19/O5/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t; cin >> t;
	while(t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll x, y, z;
		z = c;
		y = z + b;
		x = y + a;
		cout << x << ' ' << y << ' ' << z << endl;
	}
}