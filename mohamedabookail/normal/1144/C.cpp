/**
*    author:  Mohamed Abo Okail
*    created: 21/O2/2O22
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
	
	int n; cin >> n;
	vector < ll > a(n), x, y;
	map < ll , ll > mp;
	bool ok = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		ok &= (mp[a[i]] < 3);
	}
	if(!ok) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if(mp[a[i]] == 2) {
			x.push_back(a[i]);
			y.push_back(a[i]);
			mp[a[i]] = 0;
		}
		if(mp[a[i]] == 1) {
			y.push_back(a[i]);
		}
	}
	sort(all(x));
	sort(all(y));
	reverse(all(y));
	cout << "YES" << endl;
	cout << sz(x) << endl;
	for (int i = 0; i < sz(x); i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
	cout << sz(y) << endl;
	for (int i = 0; i < sz(y); i++) {
		cout << y[i] << ' ';
	}
	cout << endl;
}