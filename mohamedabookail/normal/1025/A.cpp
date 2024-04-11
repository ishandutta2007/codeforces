/**
 *    author:  Mohamed Abo_Okail
 *    created: O1/O4/2O2O
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
	int n; string s; cin >> n >> s;
	sort(s.begin(), s.end());
	bool bol = 0;
	for (int i = 1; i < n; i++) {
		if(s[i] == s[i - 1]) bol = 1;
	}
	cout << (bol || s.size() == 1 ? "YES" : "NO") << o_o;
}