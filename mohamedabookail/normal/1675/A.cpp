/**
*    author:  Mohamed Abo Okail
*    created: O5/O5/2O22
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
		ll x, y, a, b, c;
		cin >> a >> b >> c >> x >> y;
		bool ok = 1;
		if(a < x && a + c < x) {
			ok = 0;
		}
		if(a < x) {
			c -= x - a;
		}
		if(b + c < y) {
			ok = 0;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}