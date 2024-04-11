/**
*    author:  Mohamed Abo Okail
*    created: 23/1O/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s; cin >> s;
		ll ans = 0, cnt = 0;
		for (int i = 1; i < n; i++) {
			if(cnt & 1) {
				if(s[i] > s[i - 1]) {
					ans++;
					cnt++;
				}
			}
			else {
				if(s[i] < s[i - 1]) {
					ans++;
					cnt++;
				}
			}
		}
		cout << ans << endl;
	}
}