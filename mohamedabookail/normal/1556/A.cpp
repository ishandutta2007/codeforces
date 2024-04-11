/**
*    author:  Mohamed Abo Okail
*    created: 23/O9/2O21
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
		ll a, b; cin >> a >> b;
		if(a == b) {
			cout << (!a ? 0 : 1) << endl;
		}
		else if(abs(a - b) % 2 == 0) {
			cout << 2 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}