/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O22
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
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll a = 0, b = 0;
			for (int j = i; j < n; j++) {
				a += (s[j] == '+');
				b += (s[j] == '-');
				ans += (a == b);
				if(a < b) {
					ans += ((a * 2 + b) % 3 == 0);
				}
			}
		}
		cout << ans << endl;
	}
}