/**
*    author:  Mohamed Abo Okail
*    created: 22/11/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
ll ok(ll mid) {
	return mid * (mid + 1) / 2;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		ll a, b, x; cin >> a >> b>> x;
		bool ok = 0;
		while(a && b) {
			if(a < b) swap(a, b);
			if(x == a || x == b || a - b == x || ((a - x) % b == 0 && a >= x)) {
				ok = 1;
				break;
			}
			a %= b;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}