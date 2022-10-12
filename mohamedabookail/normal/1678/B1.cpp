/**
*    author:  Mohamed Abo Okail
*    created: O8/O5/2O22
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
		string s; cin >> s;
		map < char, ll > mp;
		for (int i = 0; i < n; i++) {
			mp[s[i]]++;
		}
		vector < ll > a;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if(s[i] == s[i - 1]) {
				cnt++;
			}
			else {
				a.push_back(cnt);
				cnt = 1;
			}
		}
		a.push_back(cnt);
		bool ok = 1;
		for (int i = 0; i < sz(a); i++) {
			ok &= (a[i] % 2 == 0);
		}
		if(ok) {
			cout << 0 << endl;
		}
		else {
			ll ans = min(mp['1'], mp['0']);
			ll last = -1, cur = 0;
			for (int i = 0; i < sz(a); i++) {
				if(a[i] & 1) {
					if(last == -1) {
						last = i;
					}
					else {
						cur += i - last;
						last = -1;
					}
				}
			}
			ans = min(ans, cur);
			cout << ans << endl;
		}
	}
}