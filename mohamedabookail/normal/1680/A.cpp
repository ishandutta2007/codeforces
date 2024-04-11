/**
*    author:  Mohamed Abo Okail
*    created: 13/O5/2O22
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
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if(c >= a && c <= b) {
			cout << c << endl;
		}
		else if(a >= c && a <= d) {
			cout << a << endl;
		}
		else {
			cout << a + c << endl;
		}
	}
}