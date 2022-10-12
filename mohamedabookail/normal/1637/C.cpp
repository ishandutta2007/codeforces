/**
*    author:  Mohamed Abo Okail
*    created: 12/O2/2O22
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
		if(n == 3) {
			cout << (a[1] % 2 ? -1 : a[1] / 2) << endl;
			continue;
		}
		ll ans = 0, cnt = 0;
		for (int i = 1; i < n - 1; i++) {
			ans += (a[i] / 2);
			ans += (a[i] & 1);
			cnt += (a[i] < 2);
		}
		cout << (cnt == n - 2 ? -1 : ans) << endl;
	}
}