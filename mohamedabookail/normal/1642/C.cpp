/**
*    author:  Mohamed Abo Okail
*    created: 23/O2/2O22
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
		ll n, x; cin >> n >> x;
		vector < ll > a(n);
		map < ll , ll > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		ll ans = 0;
		sort(all(a));
		for (int i = 0; i < n; i++) {
			if(!mp[a[i]]) continue;
			if(mp[1LL * a[i] * x]) {
				mp[1LL * a[i] * x]--;
				mp[a[i]]--;
			}
			else {
				mp[a[i]]--;
				ans++;
			}
		}
		cout << ans << endl;
	}
}