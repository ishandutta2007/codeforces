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
		int n;
		cin >> n;
		vector < ll > a(n);
		ll mn = 1e9 + 5, mx = 0;
		for (int i = 0; i < n; i++)  {
			cin >> a[i];
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		for (int i = 0; i < n; i++) {
			if(a[i] == mn) {
				cout << i + 1 << ' ';
				mn = -1;
			}
			if(a[i] == mx) {
				cout << i + 1 << ' ';
				mx = -1;
			}
		}
		cout << endl;
	}
}