/**
*    author:  Mohamed Abo_Okail
*    created: 2O/O7/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return (x / _gcd(x, y) * y);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > v(n), ans;
		map < int, int > mp;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i]]++;
		}
		for (int i = 0; i <= n * 2; i++) {
			int mex = 0;
			for (int j = 0; j <= n; j++) {
				if(!mp[j]) {
					mex = j;
					break;
				}
			}
			if(mex >= n) {
				for (int j = 0; j < n; j++) {
					if(v[j] != j) {
						mp[v[j]]--;
						v[j] = mex;
						mp[mex]++;
						ans.push_back(j + 1);
						break;
					}
				}
			}
			else {
				mp[v[mex]]--;
				v[mex] = mex;
				mp[mex] = 1;
				ans.push_back(mex + 1);
			}
		}
		cout << sz(ans) << endl;
		for (int i = 0; i < sz(ans); i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}