/**
*    author:  Mohamed Abo Okail
*    created: O2/O5/2O22
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
		ll a, b;
		cin >> a >> b;
		if(b % a != 0) {
			cout << 0 << ' ' << 0 << endl;
		}
		else {
			cout << 1 << ' ' << b / a << endl;
		}
	}
}