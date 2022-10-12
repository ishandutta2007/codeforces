/**
*    author:  Mohamed Abo Okail
*    created: 21/O4/2O22
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
		ll n;
		cin >> n;
		if(n >= 1900) {
			cout << "Division 1" << endl;
		}
		else if(n >= 1600) {
			cout << "Division 2" << endl;
		}
		else if(n >= 1400) {
			cout << "Division 3" << endl;
		}
		else {
			cout << "Division 4" << endl;
		}
	}
}