/**
*    author:  Mohamed Abo Okail
*    created: 31/O1/2O22
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
		string s; cin >> s;
		int a = 0, b = 0;
		for (int i = 0; i < sz(s); i++) {
			a += (s[i] == '1');
			b += (s[i] == '0');
		}
		ll ans = 0;
		if(a > b) {
			ans = b;
		}
		else if(b > a) {
			ans = a;
		}
		else {
			ans = a - 1;
		}
		cout << ans << endl;
	}
}