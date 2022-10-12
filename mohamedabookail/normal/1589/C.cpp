/**
*    author:  Mohamed Abo Okail
*    created: 14/11/2O21
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
 
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a(n);
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		vector < ll > b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(all(b));
		for (int i = 0; i < n; i++) {
			ok &= ((b[i] - a[i]) == 1 || (b[i] - a[i]) == 0);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}