/**
*    author:  Mohamed Abo Okail
*    created: 01/O8/2O21
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
		ll n; cin >> n;
		string a, b; cin >> a >> b;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if(b[i] == '1' && a[i] == '0') {
				ans++;
				a[i] = '7';
			}
			else if(b[i] == '1' && (a[i] == '1' || a[i] == '7')) {
				if(i - 1 >= 0 && a[i - 1] == '1') {
					a[i - 1] = '7';
					ans++;
				}
				else if(i + 1 < n && a[i + 1] == '1') {
					a[i + 1] = '7';
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}