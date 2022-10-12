/**
*    author:  Mohamed Abo Okail
*    created: 13/O9/2O21
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
		int n, m; cin >> n >> m;
		vector < ll > a(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		ll ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= i; j++) {
				ans += a[j] < a[i];
			}
		}
		cout << ans << endl;
	}
}