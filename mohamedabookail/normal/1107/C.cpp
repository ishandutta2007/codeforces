/**
*    author:  Mohamed Abo_Okail
*    created: 25/O6/2O2O
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
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n, k; cin >> n >> k;
	vector < ll > v(n), flag;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	string s; cin >> s; s += '0';
	ll ans = 0, sum = 0;
	for (ll i = 0; i < n; i++) {
		flag.push_back(v[i]);
		sum += v[i];
		if(s[i] != s[i + 1]) {
			if(sz(flag) > k) {
				sort(flag.begin(), flag.end());
				if(k >= sz(flag) / 2) {
					for (ll j = 0; j < sz(flag) - k; j++) {
						sum -= flag[j];
					}
				}
				else {
					sum = 0; int cnt = 0;
					for (ll j = sz(flag) - 1; j >= 0 ; j--) {
						sum += flag[j];
						cnt ++;
						if(cnt == k) break;
					}
				}
			}
			ans += sum;
			sum = 0;
			flag.clear();
		}
	}
	cout << ans << endl;
}