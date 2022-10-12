/**
 *    author:  Mohamed Abo_Okail
 *    created: 1O/O6/2O2O
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
	int a = 0, b = 0, c = 0;
	while(t--) {
		int x, y, z; cin >> x >> y >> z;
		a += x;
		b += y;
		c += z;
	}
	cout << (!a && !b && !c ? "YES" : "NO") << endl;
}