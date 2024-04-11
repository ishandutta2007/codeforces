/**
*    author:  Mohamed Abo_Okail
*    created: 21/1O/2O2O
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
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a(n);
		ll mx = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		ll ans = -1;
		for (int i = 0; i < n; i++) {
			if(!i) {
				if(a[i] == mx && a[i] > a[i + 1]) {
					ans = i;
					break;
				}
			}
			else if(i == n - 1) {
				if(a[i] == mx && a[i] > a[i - 1]) {
					ans = i;
					break;
				}
			}
			else {
				if(a[i] == mx && (a[i] > a[i - 1] || a[i] > a[i + 1])) {
					ans = i;
					break;
				}
			}
		}
		cout << (ans == -1 ? -1 : ++ans) << endl;
	}
}