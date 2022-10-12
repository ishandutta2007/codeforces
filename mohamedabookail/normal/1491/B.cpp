/**
*    author:  Mohamed Abo Okail
*    created: 16/O4/2O21
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
		ll n, u, v; cin >> n >> u >> v;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool ok = 0;
		for (int i = 1; i < n; i++) {
			if(abs(a[i] - a[i - 1]) > 1) {
				ok = 1;
				break;
			}
		}
		if(ok) {
			cout << 0 << endl;
		}
		else if(*min_element(all(a)) == *max_element(all(a))) {
			cout << min(u + v, v + v) << endl;
		}
		else {
			cout << min(u, v) << endl;
		}
	}
}