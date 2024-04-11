/**
 *    author:  Mohamed Abo_Okail
 *    created: 14/O5/2O2O
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
		ll n, m; cin >> n >> m;
		if(n == 1) cout << 0;
		else if(n == 2) cout << m;
		else cout << m * 2;
		cout << endl;
	}
}