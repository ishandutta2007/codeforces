/**
*    author:  Mohamed Abo Okail
*    created: 16/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
  
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			a += (s[i] == 'M');
			b += (s[i] == 'T');
		}
		if(a * 2 != b) {
			cout << "NO" << endl;
			continue;
		}
		vector < ll > idx;
		map < ll, ll > mp;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if(s[i] == 'M') {
				idx.push_back(i);
			}
		}
		for (int i = 0; i < n; i++) {
			if(s[i] == 'T') {
				cnt++;
			}
			else {
				mp[i] = cnt;
			}
		}
		bool ok = 1;
		for (int i = 0; i < sz(idx); i++) {
			ll x = mp[idx[i]] - (i + 1);
			ll y = (n / 3 * 2) - mp[idx[i]] - (sz(idx) - i);
			if(x < 0 || y < 0) {
				ok = 0;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}