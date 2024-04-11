/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O5/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		ll cnt = 1e6, cur = 0;
		map < int, int > mp;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == '1') {
				mp[1] = (i + 1); 
			}
			if(s[i] == '2') {
				mp[2] = (i + 1); 
			}
			if(s[i] == '3') {
				mp[3] = (i + 1); 
			}
			if(mp[1] && mp[2] && mp[3]) {
				cur = max(mp[1], max(mp[2], mp[3])) - min(mp[1], min(mp[2], mp[3])) + 1;
				cnt = min(cnt, cur);
			}
		}
		cout << (cnt == 1e6 ? 0 : cnt) << endl;
	}
}