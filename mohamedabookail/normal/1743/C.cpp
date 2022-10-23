/**
*    author:  Mohamed Abo Okail
*    created: 17/1O/2O22
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
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 0, mn = 1e9, cnt = 0;
		bool ok = 0;
		for (int i = n - 1; i >= 0 ; i--) {
			if(s[i] == '1') ok = 1;
			if(s[i] == '0') ok = 0;
			if(ok) {
				ans += a[i];
				mn = min(mn, a[i]);
				cnt++;
			}
			else {
				if(cnt) {
					ans += a[i];
					mn = min(mn, a[i]);
				}
				if(mn != 1e9) {
					ans -= mn;
				}
				mn = 1e9;
				cnt = 0;
			}
		}
		cout << ans << endl;
	}
}