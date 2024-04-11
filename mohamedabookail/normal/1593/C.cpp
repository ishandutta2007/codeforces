/**
*    author:  Mohamed Abo Okail
*    created: 19/1O/2O21
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
		int n, k; cin >> n >> k;
		map < ll , ll > mp;
		for (int i = 0; i < k; i++) {
			ll x; cin >> x;
			mp[x]++;
		}
		vector < ll > a;
		int catPlace = 0, ans = 0;
		for(auto it : mp) {
			a.push_back(it.first);
		}
		sort(all(a));
		for (int i = sz(a) - 1; i >= 0 ; i--) {
			if(n - a[i] < n - catPlace) {
				catPlace += n - a[i];
				mp[a[i]]--;
				ans++;
			}
			else break;
			if(mp[a[i]]) i++;
		}
		cout << ans << endl;
	}
}