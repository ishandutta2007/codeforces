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
 
bool ok(double n, double mid, double cur) {
	double a = n - 2 + mid, b = 2 - mid;
	return (n - a * b <= cur && a * b <= n);
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		ll n; cin >> n;
		if(!n) cout << "Y 0.000000000 0.000000000" << endl;
		else if(n <= 3) cout << 'N' << endl;
		else {
			ll lo = 0, hi = 1e9;
			double a = 0.00, b = 0.00, cur = n;
			while(lo <= hi) {
				double mid = (lo + hi) / 2;
				double flag = mid / 1e9;
				if(ok(n, flag, cur)) {
					a = n - 2 + flag;
					b = 2 - flag;
					cur = n - (a * b);
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			cout << fixed << setprecision(9);
			cout << 'Y' << ' ' << a << ' ' << b << endl;
		}
	}
}