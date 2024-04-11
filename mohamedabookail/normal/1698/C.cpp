/**
*    author:  Mohamed Abo Okail
*    created: 28/O6/2O22
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
		map < ll , bool > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]] = 1;
		}
		sort(all(a));
		bool ok = 1;
		for (int i = 2; i < n; i++) {
			ok &= mp[a[i] + a[i - 1] + a[i - 2]];
		}
		for (int i = 1; i < n - 1; i++) {
			ok &= mp[a[i] + a[0] + a[n - 1]];
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}