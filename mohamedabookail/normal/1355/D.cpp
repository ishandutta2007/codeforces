/**
 *    author:  Mohamed Abo_Okail
 *    created: 16/O5/2O2O
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
	ll n, s; cin >> n >> s;
	if(s >= 2 * n) {
		cout << "YES" << endl;
		for (int i = 1; i < n; i++) {
			cout << 2 << ' ';
		}
		cout << s - ((n - 1) * 2) << endl;
		cout << 1 << endl;
	}
	else cout << "NO" << endl;
}