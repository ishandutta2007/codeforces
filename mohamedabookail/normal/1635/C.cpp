/**
*    author:  Mohamed Abo Okail
*    created: 2O/O2/2O22
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
		vector < ll > a(n), b;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		b = a;
		sort(all(b));
		if(a == b) {
			cout << 0 << endl;
			continue;
		}
		a[n - 3] = a[n - 2] - a[n - 1];
		if(a[n - 3] <= a[n - 2] && a[n - 2] <= a[n - 1]) {
			cout << n - 2 << endl;
			for (int i = 0; i < n - 2; i++) {
				cout << i + 1 << ' ' << n - 1 << ' ' << n << endl;
			}
		}
		else {
			cout << -1 << endl;
		}
	}
}