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
		ll n;
		cin >> n;
		vector < ll > a(n);
		ll odd = 0;
		bool ok1 = 0, ok2 = 0, ok3 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			odd += (a[i] & 1);
			ok1 |= (a[i] == 0);
			ok2 |= (a[i] == 1);
			ok3 |= (a[i] == 2);
		}
		sort(all(a));
		if(odd == n || odd == 0) {
			cout << "YES" << endl;
		}
		else if(ok1 && ok2) {
			cout << "NO" << endl;
		}
		else if(ok2 && ok3) {
			cout << "NO" << endl;
		}
		else if(!ok2) {
			cout << "YES" << endl;
		}
		else {
			bool ok = 1;
			for (int i = 1; i < n; i++) {
				if(a[i] - a[i - 1] == 1) {
					ok = 0;
					break;
				}
			}
			cout << (ok ? "YES" : "NO") << endl;
		}
	}
}