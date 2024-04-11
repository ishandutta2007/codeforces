/**
 *    author:  Mohamed Abo_Okail
 *    created: 21/O4/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define line "\n"
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
		vector < ll > v(n);
		char ch = '0';
		ll a = -1, b = -1e10, sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			if(v[i] > 0) {
				if(b != -1e10) {
					sum += b;
					b = -1e10;
					ch = 'b';
				}
				a = max(a, v[i]);
			}
			if(v[i] < 0) {
				if(a != -1) {
					sum += a;
					a = -1;
					ch = 'a';
				}
				b = max(b, v[i]);
			}
		}
		if(a != -1 && ch == 'b' || (!sum && a != -1)) sum += a;
		if(b != -1e10 && ch == 'a' || (!sum && b != -1e10)) sum += b;
		cout << sum << endl;
	}
}