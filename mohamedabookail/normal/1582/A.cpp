/**
*    author:  Mohamed Abo Okail
*    created: 24/1O/2O21
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
		ll sum = a + b * 2 + c * 3;
		cout << sum % 2 << endl;
	}
}