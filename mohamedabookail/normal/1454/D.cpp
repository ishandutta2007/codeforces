/**
*    author:  Mohamed Abo_Okail
*    created: 24/11/2O2O
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
		vector < ll > ans;
		for (ll i = 2; i * i <= n; i++) {
			vector < ll > x;
			ll cur = n, flag = i;
			while(flag <= cur) {
				if(cur % flag == 0 && (cur / flag) % flag == 0) {
					x.push_back(flag);
					cur /= flag;
				}
				else {
					flag += flag;
				}
			}
			x.push_back(cur);
			if(sz(x) > sz(ans)) {
				ans.clear();
				ans = x;
			}
		}
		if(!sz(ans)) {
			cout << 1 << endl << n << endl;
			continue;
		}
		cout << sz(ans) << endl;
		for (int i = 0; i < sz(ans); i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}