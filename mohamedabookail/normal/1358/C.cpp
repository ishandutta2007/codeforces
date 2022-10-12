/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O5/2O2O
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
		ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << (x2 - x1) * (y2 - y1) + 1 << endl;
	}
}