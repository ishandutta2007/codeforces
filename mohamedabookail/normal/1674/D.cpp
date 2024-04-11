/**
*    author:  Mohamed Abo Okail
*    created: O3/O5/2O22
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
		for (int i = n - 1; i > 0 ; i -= 2) {
			if(a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
			}
		}
		bool ok = 1;
		for (int i = 1; i < n; i++) {
			ok &= (a[i] >= a[i - 1]);
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}