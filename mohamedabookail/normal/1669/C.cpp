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
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool ok = 1;
		for (int i = 2; i < n; i++) {
			ok &= (a[i] % 2) == (a[i - 2] % 2);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}