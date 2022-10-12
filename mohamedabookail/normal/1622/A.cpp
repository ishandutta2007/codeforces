/**
*    author:  Mohamed Abo Okail
*    created: 27/12/2O21
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
		ll a, b, c;
		cin >> a >> b >> c;
		if(a == b + c || b == a + c || c == a + b) {
			cout << "YES" << endl;
		}
		else if(a == b && c % 2 == 0) {
			cout << "YES" << endl;
		}
		else if(a == c && b % 2 == 0) {
			cout << "YES" << endl;
		}
		else if(b == c && a % 2 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}