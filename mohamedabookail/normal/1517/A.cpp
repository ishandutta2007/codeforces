/**
*    author:  Mohamed Abo Okail
*    created: 23/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
  
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a;
		a.push_back(2050);
		for (int i = 0; i < 15; i++) {
			a.push_back(a.back() * 10);
		}
		reverse(all(a));
		ll ans = 0;
		for (int i = 0; i < 16; i++) {
			ll cur = n / a[i];
			ans += cur;
			n -= cur * a[i];
		}
		cout << (!n ? ans : -1) << endl;
	}
}