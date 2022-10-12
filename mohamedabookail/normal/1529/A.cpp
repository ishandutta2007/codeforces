/**
*    author:  Mohamed Abo Okail
*    created: 24/O5/2O21
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
		int n; cin >> n;
		vector < ll > a(n);
		map < ll, ll > mp;
		ll mn = 1e9;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			mn = min(mn, a[i]);
		}
		cout << n - mp[mn] << endl;
	}
}