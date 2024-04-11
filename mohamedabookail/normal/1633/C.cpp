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
		ll a1, b1; cin >> a1 >> b1;
		ll a2, b2; cin >> a2 >> b2;
		ll k, w, a; cin >> k >> w >> a;
		if((a2 + b1 - 1) / b1 <= (a1 + b2 - 1) / b2) {
			cout << "YES" << endl;
			continue;
		}
		bool ok = 0;
		for (int i = 0; i <= k; i++) {
			ll aa1 = a1 + i * a;
			ll bb1 = b1 + (k - i) * w;
			if((a2 + bb1 - 1) / bb1 <= (aa1 + b2 - 1) / b2) {
				ok = 1;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}