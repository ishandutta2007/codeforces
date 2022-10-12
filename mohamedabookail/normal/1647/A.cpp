/**
*    author:  Mohamed Abo Okail
*    created: 11/O3/2O22
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
		int n; cin >> n;
		string a = "", b = "";
		for (int i = 0; i < 500; i++) {
			a.push_back('2');
			a.push_back('1');

			b.push_back('1');
			b.push_back('2');
		}
		ll x = 0, y = 0;
		bool ok = 0;
		string ans = "";
		for (int i = 0; i < sz(a); i++) {
			ans.push_back(a[i]);
			x += (a[i] - '0');
			if(x == n) {
				ok = 1;
				break;
			}
		}
		if(!ok) {
			ans.clear();
			for (int i = 0; i < sz(b); i++) {
				ans.push_back(b[i]);
				y += (b[i] - '0');
				if(y == n) {
					break;
				}
			}
		}
		cout << ans << endl;
	}
}