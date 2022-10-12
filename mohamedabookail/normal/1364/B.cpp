/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) ll(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		vector < int > v(n), flag, ans;
		bool bol1 = 0, bol2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if(n == 2) {
			cout << 2 << endl;
			cout << v[0] << ' ' << v[1] <<  endl;
			continue;
		}
		for (int i = 1; i < n; i++) {
			flag.push_back(v[i] - v[i - 1]);
		}
		for (int i = 0; i < n - 1; i++) {
			if(flag[i] > 0) {
				bol1 = 1;
				if(bol2) {
					if(!ans.size()) {
						ans.push_back(v[0]);
					}
					ans.push_back(v[i]);
				}
				bol2 = 0;
			}
			if(flag[i] < 0) {
				bol2 = 1;
				if(bol1) {
					if(!ans.size()) {
						ans.push_back(v[0]);
					}
					ans.push_back(v[i]);
				}
				bol1 = 0;
			}
		}
		if((bol1 || bol2) && !ans.size()) ans.push_back(v[0]);
		if(bol1 || bol2) ans.push_back(v[n - 1]);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if(i != ans.size() - 1) cout << ' ';
		}
		cout << endl;
	}
}