/**
*    author:  Mohamed Abo Okail
*    created: 16/1O/2O22
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
		char ch; cin >> ch;
		string s; cin >> s;
		vector < ll > a, b;
		for (int i = 0; i < n; i++) {
			if(s[i] == ch) {
				a.push_back(i + 1);
			}
			if(s[i] == 'g') {
				b.push_back(i + 1);
			}
		}
		ll ans = 0;
		for (int i = 0; i < sz(a); i++) {
			ll lo = 0, hi = sz(b) - 1, mid = 0, cur = -1;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(b[mid] >= a[i]) {
					cur = b[mid];
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			if(cur == -1) {
				ans = max(ans, n - a[i] + b[0]);
			}
			else {
				ans = max(ans, cur - a[i]);
			}
		}
		cout << ans << endl;
	}
}