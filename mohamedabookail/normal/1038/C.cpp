/**
*    author:  Mohamed Abo_Okail
*    created: 26/O6/2O2O
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
	deque < ll > a(n), b(n);
	ll A = 0, B = 0, flag = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	while(sz(a) || sz(b)) {
		if(flag == 1) {
			if(sz(a) && sz(b) && a.back() >= b.back()) {
				A += a.back();
				a.pop_back();
			}
			else if(sz(a) && !sz(b)) {
				A += a.back();
				a.pop_back();
			}
			else {
				b.pop_back();
			}
		}
		else {
			if(sz(b) && sz(a) && b.back() >= a.back()) {
				B += b.back();
				b.pop_back();
			}
			else if(sz(b) && !sz(a)) {
				B += b.back();
				b.pop_back();
			}
			else {
				a.pop_back();
			}
		}
		flag *= -1;
	}
	cout << A - B << endl;
}