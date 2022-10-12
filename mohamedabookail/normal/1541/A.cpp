/**
*    author:  Mohamed Abo Okail
*    created: 25/O6/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		if(n & 1) {
			for (int i = 1; i <= n - 3; i += 2) {
				cout << i + 1 << ' ' << i << ' ';
			}
			cout << n << ' ' << n - 2 << ' ' << n - 1;
		}
		else {
			for (int i = 1; i <= n; i += 2) {
				cout << i + 1 << ' ' << i << ' ';
			}
		}
		cout << endl;
	}
}