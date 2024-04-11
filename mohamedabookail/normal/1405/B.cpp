/**
*    author:  Mohamed Abo_Okail
*    created: O6/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > v(n), foo;
		map < ll, ll > mp;
		ll ans = 0, idx = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if(v[i] < 0) {
				foo.push_back(i);
				mp[i] = -v[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if(v[i] > 0) {
				for (int j = idx; j < sz(foo); j++) {
					if(foo[j] > i) {
						ll flag = min(v[i], mp[foo[j]]);
						v[i] -= flag;
						mp[foo[j]] -= flag;
						if(v[i] == 0) {
							idx = j;
							break;
						}
					}
					idx = j;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if(v[i] > 0) {
				ans += v[i];
			}
		}
		cout << ans << endl;
	}
}