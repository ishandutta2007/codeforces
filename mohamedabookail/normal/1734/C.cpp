/**
*    author:  Mohamed Abo Okail
*    created: 24/O9/2O22
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
		ll n;
		cin >> n;
		string s; cin >> s;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				if(s[j - 1] == '1') break;
				if(s[j - 1] == '0') {
					ans += i;
					s[j - 1] = '2';
				}
			}
		}
		cout << ans << endl;
	}
}