/**
*    author:  Mohamed Abo Okail
*    created: O2/11/2O21
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
		string a, b; cin >> a >> b;
		map < char , int > mp;
		for (int i = 0; i < sz(a); i++) {
			mp[a[i]] = i + 1;
		}
		ll ans = 0;
		for (int i = 1; i < sz(b); i++) {
			ans += abs(mp[b[i]] - mp[b[i - 1]]);
		}
		cout << ans << endl;
	}
}