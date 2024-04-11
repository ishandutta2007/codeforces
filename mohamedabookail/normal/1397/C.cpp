/**
*    author:  Mohamed Abo_Okail
*    created: 3O/O8/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return (x / _gcd(x, y) * y);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	vector < ll > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if(n == 1) {
		cout << "1 1" << endl;
		cout << -v[0] << endl;
		cout << "1 1" << endl;
		cout << 0 << endl;
		cout << "1 1" << endl;
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << ' ' << n - 1 << endl;
	for (int i = 0; i < n - 1; i++) {
		ll flag = v[i] * (n - 1);
		cout << flag;
		if(i != n - 2) cout << ' ';
		v[i] += flag;
	}
	cout << endl;
	cout << n << ' ' << n << endl;
	cout << -v[n - 1] << endl;
	v[n - 1] = 0;
	cout << 1 << ' ' << n << endl;
	for (int i = 0; i < n; i++) {
		v[i] *= -1;
		cout << v[i];
		if(i != n - 1) cout << ' ';
	}
}