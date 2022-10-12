/**
*    author:  Mohamed Abo Okail
*    created: 27/O3/2O22
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
		for (int i = 0; i < n - 1; i++) {
			if(s[i] == '0' && s[i + 1] == '0') {
				ans += 2;
			}
			else if(s[i] == '0' && i + 2 < n && s[i + 2] == '0') {
				ans++;
			}
		}
		cout << ans << endl;
	}
}