/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O3/2O2O
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
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; s.assign(n, '5'); s.back() = '4';
		cout << (n == 1 ? "-1" : s) << o_o;
	}
}