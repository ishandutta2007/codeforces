/**
*    author:  Mohamed Abo Okail
*    created: 1O/O5/2O22
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
		int n, m;
		cin >> n >> m;
		vector < string > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 1e9;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ll cur = 0;
				for (int k = 0; k < m; k++) {
					if(a[i][k] == a[j][k]) {
						continue;
					}
					cur += abs((a[i][k] - 'a') - (a[j][k] - 'a'));
				}
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
}