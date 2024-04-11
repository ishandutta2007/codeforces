/**
 *    author:  Mohamed Abo_Okail
 *    created: 11/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
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
	ll n; cin >> n;
	vector < ll > a(n), b(n), c(n);
	ll mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b = a;
	for (int i = 0; i < n; i++) {
		ll sum = b[i];
		for (int j = i + 1; j < n; j++) {
			if(b[j] > b[j - 1]) b[j] = b[j - 1];
			sum += b[j];
		}
		for (int j = i - 1; j >= 0 ; j--) {
			if(b[j] > b[j + 1]) b[j] = b[j + 1];
			sum += b[j];
		}
		if(sum > mx) {
			c.clear();
			c = b;
			mx = sum;
		}
		b.clear();
		b = a;
	}
	for (int i = 0; i < n; i++) {
		cout << c[i];
		if(i != n - 1) cout << ' ';
	}
}