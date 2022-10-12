/**
*    author:  Mohamed Abo Okail
*    created: 14/O5/2O22
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
		ll a = n, b = n;
		ll mn = a / 6;
		a -= mn * 6;
		mn += a / 4;
		if(a % 4 == 2 && mn) {
			mn++;
			a = 0;
		}
		ll mx = b / 4;
		b -= mx * 4;
		if(b % 2 == 0 && a % 4 == 0) {
			cout << mn << ' ' << mx << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
}