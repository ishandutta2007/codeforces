/**
*    author:  Mohamed Abo Okail
*    created: 01/O8/2O21
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
		ll n; cin >> n;
		if(n % 2 == 0) {
			cout << 2 << ' ' << n << endl;
		}
		else {
			cout << 2 << ' ' << n - 1 << endl;
		}
	}
}