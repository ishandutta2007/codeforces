/**
*    author:  Mohamed Abo Okail
*    created: 25/O9/2O22
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
		int n, c;
		cin >> n >> c;
		map < int , int > mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		ll ans = 0;
		for(auto it : mp) {
			ans += min(c, it.second);
		}
		cout << ans << endl;
	}
}