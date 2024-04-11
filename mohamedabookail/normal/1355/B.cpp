/**
 *    author:  Mohamed Abo_Okail
 *    created: 16/O5/2O2O
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
		ll n; cin >> n;
		vector < int > v(n), x;
		map < int, int > mp;
		//set < int > st;
		ll cnt = 0, flag = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i]]++;
			if(mp[v[i]] == 1) x.push_back(v[i]);
		}
		sort(x.begin(), x.end());
		for (int i = 0; i < x.size(); i++) {
			cnt += mp[x[i]] / x[i];
			flag += mp[x[i]] % x[i];
			cnt += flag / x[i];
			flag -= (flag / x[i]) * x[i];
		}
		cout << cnt << endl;
	}
}