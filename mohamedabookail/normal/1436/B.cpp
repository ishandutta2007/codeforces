/**
*    author:  Mohamed Abo_Okail
*    created: 24/1O/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	map < ll, ll > mp;
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= 1e5; j++) {
			bool bolx = 1;
			for (int k = 2; k * k <= j; k++) {
				if(j % k == 0) {
					bolx = 0;
					break;
				}
			}
			if(bolx) continue;
			ll x = (i - 1) * j + 1;
			bool bol = 1;
			for (ll k = 2; k * k <= x; k++) {
				if(x % k == 0) {
					bol = 0;
					break;
				}
			}
			if(bol) {
				mp[i] = j;
				break;
			}
		}
	}
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(i == j) cout << 1 << ' ';
				else {
					cout << mp[n] << ' ';
				}
			}
			cout << endl;
		}
	}
}