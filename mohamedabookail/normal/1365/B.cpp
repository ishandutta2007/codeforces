/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O6/2O2O
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
		int n; cin >> n;
		vector < int > v(n), x(n);
		bool bol = 1;
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			cur += x[i];
		}
		for (int i = 1; i < n; i++) {
			if(v[i] < v[i - 1]) bol = 0;
		}
		if(cur != n && cur != 0) cout << "YES" << endl;
		else if(bol) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}