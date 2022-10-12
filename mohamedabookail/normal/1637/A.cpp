/**
*    author:  Mohamed Abo Okail
*    created: 12/O2/2O22
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
		int n; cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll mn = a[n - 1];
		bool ok = 0;
		for (int i = n - 2; i >= 0 && !ok; i--) {
			ok |= (a[i] > mn);
			mn = min(mn, a[i]);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}