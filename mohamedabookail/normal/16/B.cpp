/**
*    author:  Mohamed Abo Okail
*    created: 22/O4/2O22
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
	
	ll n, m;
	cin >> n >> m;
	vector < pair < ll , ll > > a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(all(a));
	reverse(all(a));
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		ans += min(a[i].second, n) * a[i].first;
		n -= min(a[i].second, n);
	}
	cout << ans << endl;
}