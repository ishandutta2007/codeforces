/**
*    author:  Mohamed Abo Okail
*    created: O5/O5/2O22
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
		int n;
		cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 0;
		reverse(all(a));
		for (int i = 1; i < n; i++) {
			while(a[i] >= a[i - 1]) {
				a[i] /= 2;
				ans++;
				if(a[i] == 0 && a[i - 1] == 0) {
					ans = -1;
					break;
				}
			}
			if(ans == -1) break;
		}
		cout << ans << endl;
	}
}