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
	int n; cin >> n;
	vector < ll > v(n / 2);
	deque < ll > a, b;
	for (int i = 0; i < n / 2; i++) {
		cin >> v[i];
	}
	a.push_back(0);
	b.push_front(v[0]);
	for (int i = 1; i < n / 2; i++) {
		if(v[i] > b.front()) {
			if(v[i] - b.front() >= a.back()) {
				b.push_front(b.front());
				a.push_back(v[i] - b.front());
			}
			else {
				a.push_back(a.back());
				b.push_front(v[i] - a.back());
			}
		}
		else {
			b.push_front(v[i] - a.back());
			a.push_back(a.back());
		}
	}
	for (int i = 0; i < sz(a); i++) {
		cout << a[i] << ' ';
	}
	for (int i = 0; i < sz(b); i++) {
		cout << b[i];
		if(i != sz(b) - 1) cout << ' ';
	}
}