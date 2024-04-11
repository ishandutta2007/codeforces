/**
*    author:  Mohamed Abo Okail
*    created: 22/O1/2O22
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
		ll a, b, k;
		cin >> a >> b >> k;
		if(b == 1) {
			cout << "NO" << endl;
			continue;
		}
		if(k == 0){
			if(b == 1) {
				cout << "NO" << endl;
			}
			else if(a == b) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
			continue;
		}
		ll cur = (b - a + 1) / 2 + ((a & 1) && (b & 1));
		cout << (cur <= k ? "YES" : "NO") << endl;
	}
}