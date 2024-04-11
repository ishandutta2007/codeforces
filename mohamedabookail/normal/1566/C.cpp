/**
*    author:  Mohamed Abo Okail
*    created: 13/O9/2O21
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
		string a, b;
		cin >> a >> b;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				ans += 2;
				continue;
			}
			if(i == n - 1) {
				ans += a[i] == '0';
				continue;
			}
			if(a[i] != a[i + 1] && a[i + 1] == b[i + 1]) {
				ans += 2;
				i++;
			}
			else {
				ans += a[i] == '0';
			}
		}
		cout << ans << endl;
	}
}