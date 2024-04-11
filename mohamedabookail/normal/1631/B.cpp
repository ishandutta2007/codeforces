/**
*    author:  Mohamed Abo Okail
*    created: 28/O1/2O22
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
		ll ans = 0, cur = a[n - 1];
		reverse(all(a));
		for (int i = 0; i < n; i++) {
			if(a[i] == cur) continue;
			ans++;
			i = i * 2 - 1;
		}
		cout << ans << endl;
	}
}