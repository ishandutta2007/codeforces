/**
*    author:  Mohamed Abo Okail
*    created: 11/1O/2O21
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
		vector < pair < int, int > > a(n);
		map < int, int > mp1, mp2;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			mp1[a[i].first]++;
			mp2[a[i].second]++;
		}
		ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
		for (int i = 0; i < n; i++) {
			ans -= 1LL * (mp1[a[i].first] - 1) * (mp2[a[i].second] - 1);
		}
		cout << ans << endl;
	}
}