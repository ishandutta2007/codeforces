/**
*    author:  Mohamed Abo_Okail
*    created: 25/O9/2O2O
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
		map < ll, ll > mp;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			int cnt = 0;
			while(oo) {
				oo /= 2;
				cnt++;
			}
			mp[cnt]++;
		}
		ll ans = 0;
		for(auto it : mp) {
			ans += it.second * (it.second - 1) / 2;
		}
		cout << ans << endl;
	}
}