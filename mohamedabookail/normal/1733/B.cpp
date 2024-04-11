/**
*    author:  Mohamed Abo Okail
*    created: 19/O9/2O22
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
		ll n, a, b;
		cin >> n >> a >> b;
		if(a == 0 && b != 0 && (n - 1) % b == 0) {
			int x = 2;
			for (int i = 0; i < (n - 1) / b; i++) {
				for (int j = 0; j < b; j++) {
					cout << x << ' ';
				}
				x += b;
			}
			cout << endl;
		}
		else if(b == 0 && a != 0 && (n - 1) % a == 0) {
			int x = 2;
			for (int i = 0; i < (n - 1) / a; i++) {
				for (int j = 0; j < a; j++) {
					cout << x << ' ';
				}
				x += a;
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}