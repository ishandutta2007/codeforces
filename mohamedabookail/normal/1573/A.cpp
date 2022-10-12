/**
*    author:  Mohamed Abo Okail
*    created: 23/O9/2O21
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
		string s; cin >> s;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if(s[i] == '0') continue;
			if(i == n - 1) {
				ans += (s[i] - '0');
			}
			else {
				ans += (s[i] - '0') + 1;
			}
		}
		cout << ans << endl;
	}
}