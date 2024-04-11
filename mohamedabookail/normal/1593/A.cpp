/**
*    author:  Mohamed Abo Okail
*    created: 19/1O/2O21
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
	
	int t; cin >> t;
	while(t--) {
		ll a, b, c; cin >> a >> b >> c;
		ll mx = max(a, max(b, c));
		if(a == b && b == c) {
			cout << "1 1 1" << endl;
		}
		else if(a == mx) {
			cout << (a == b || a == c) << ' ' << a - b + 1 << ' ' << a - c + 1 << endl;
		}
		else if(b == mx) {
			cout << b - a + 1 << ' ' << (b == a || b == c) << ' ' << b - c + 1 << endl;
		}
		else {
			cout << c - a + 1 << ' ' << c - b + 1 << ' ' << (c == a || c == b) << endl;
		}
	}
}