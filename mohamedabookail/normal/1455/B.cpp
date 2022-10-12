/**
*    author:  Mohamed AboOkail
*    created: O3/12/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
ll ok(ll n) {
	return n * (n + 1) / 2;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll lo = 0, hi = n, mid = 0, ans = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(ok(mid) < n) {
				lo = mid + 1;
			}
			else {
				ans = mid;
				hi = mid - 1;
			}
		}
		cout << ((ok(ans) - n == 1) ? ++ans : ans) << endl;
	}
}