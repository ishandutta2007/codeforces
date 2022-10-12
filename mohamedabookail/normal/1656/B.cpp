/**
*    author:  Mohamed Abo Okail
*    created: 24/O3/2O22
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

	int t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		vector < ll > a(n);
		map < ll , bool > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]] = 1;
		}
		sort(all(a));
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			ok |= (mp[a[i] - k]);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}