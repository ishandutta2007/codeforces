/**
*    author:  Mohamed Abo Okail
*    created: 22/O3/2O22
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

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s; cin >> s;
		string a = "", b = "";
		ll ans = 0, tot = 0;
		for (int i = 0; i < n; i++) {
			a.push_back(s[i]);
			if(sz(a) == 1) continue;
			bool ok = 1;
			if(sz(a) % 2 == 0) {
				for (int i = 0; i < sz(a) / 2; i++) {
					if(a[i] == '(' && a[sz(a) - i - 1] == ')') {
						ok = 1;
					}
					else {
						ok = 0;
						break;
					}
				}
				if(ok) {
					tot += sz(a);
					ans++;
					a.clear();
					continue;
				}
			}
			ok = 1;
			for (int i = 0; i < sz(a) / 2; i++) {
				ok &= (a[i] == a[sz(a) - i - 1]);
				if(!ok) break;
			}
			if(ok) {
				ans++;
				tot += sz(a);
				a.clear();
			}
		}
		cout << ans << ' ' << n - tot << endl;
	}
}