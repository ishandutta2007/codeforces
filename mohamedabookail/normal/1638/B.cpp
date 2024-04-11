/**
*    author:  Mohamed Abo Okail
*    created: 16/O2/2O22
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
		vector < int > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int even = 0, odd = 0;
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			if(a[i] & 1) {
				ok &= (a[i] >= odd);
				odd = max(a[i], odd);
			}
			else {
				ok &= (a[i] >= even);
				even = max(a[i], even);
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}