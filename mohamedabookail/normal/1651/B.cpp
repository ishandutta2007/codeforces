/**
*    author:  Mohamed Abo Okail
*    created: 1O/O3/2O22
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

	vector < ll > a;
	ll x = 1;
	while(x <= 1e9) {
		a.push_back(x);
		x *= 3;
	}
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		if(n <= sz(a)) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << a[i] << ' ';
			}
			cout << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}