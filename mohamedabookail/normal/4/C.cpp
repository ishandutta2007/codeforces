/**
 *    author:  Mohamed Abo_Okail
 *    created: 2O/O6/2O2O
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
	int n; cin >> n;
	vector < string > v(n);
	map < string, int > mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for(int i = 0; i < n; i++) {
		string s = v[i];
		if(!mp[s]) {
			cout << "OK" << endl;
			mp[s]++;
		}
		else {
			cout << s << mp[s] << endl;
			mp[s]++;
		}
	}
}