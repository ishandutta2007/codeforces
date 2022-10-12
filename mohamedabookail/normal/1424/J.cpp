/**
*    author: Mohamed AboOkail
*    created: O5/1O/2O2O
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
	int n; cin >> n;
	vector < ll > a(n), b;
	for (int i = 2; i <= 1e6; i++) {
		bool bol = 1;
		for (ll j = 2; j * j <= i; j++) {
			if(i % j == 0) {
				bol = 0;
				break;
			}
		}
		if(bol) {
			b.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map < ll, ll > mp;
	for (int i = 0; i < n; i++) {
		ll ans = 1;
		ll lo = 0, hi = sz(b) - 1, mid = 0, ans2 = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(b[mid] <= a[i]) {
				ans2 = mid;
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		ans += ans2 + 1;
		for (int j = 0; j < ans2; j++) {
			ll x = pow(b[j], 2);
			if(x <= a[i]) ans--;
			else break;
		}
		cout << ans << endl;
	}
}