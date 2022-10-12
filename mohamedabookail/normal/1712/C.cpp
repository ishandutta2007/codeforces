/**
*    author:  Mohamed Abo Okail
*    created: 15/O8/2O22
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
		int n;
		cin >> n;
		vector < int > a(n);
		map < int , int > mp, mp2;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		ll ans = 0, mx = 1e5 + 1, tot = sz(mp);
		for (int i = n - 1; i >= 0 ; i--) {
			if(a[i] <= mx) {
				mx = a[i];
			}
			else {
				break;
			}
			mp[a[i]]--;
			if(mp[a[i]] == 0) {
				ans += !mp2[a[i]];
				mp2[a[i]] = 1;
			}
			else if(a[i - 1] != a[i]) {
				break;
			}
		}
		cout << tot - ans << endl;
	}
}