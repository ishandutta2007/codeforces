/**
*    author:  Mohamed Abo Okail
*    created: 1O/O4/2O22
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
		ll n; cin >> n;
		set < ll > st;
		for (ll i = 1; i * i <= n; i++) {
			st.insert(i);
			if(1LL * i * i * i <= n) {
				st.insert(i * i * i);
			}
		}
		cout << sz(st) << endl;
	}
}