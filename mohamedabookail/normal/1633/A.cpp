/**
*    author:  Mohamed Abo Okail
*    created: 31/O1/2O22
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
		if(n % 7 == 0) {
			cout << n << endl;
		}
		else {
			n /= 10;
			for (int i = 0; i <= 9; i++) {
				n *= 10;
				n += i;
				if(n % 7 == 0) {
					cout << n << endl;
					break;
				}
				n /= 10;
			}
		}
	}
}