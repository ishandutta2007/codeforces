/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O3/2O2O
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
	int n, k; string s; cin >> n >> k >> s;
	if(n == 1 && k) return cout << 0, 0;
	if(s[0] != '1' && k) s[0] = '1', k--;
	for (int i = 1; i < n; i++) {
		if(s[i] != '0' && k) s[i] = '0', k--;
	}
	cout << s << o_o;
}