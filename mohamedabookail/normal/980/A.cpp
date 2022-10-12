/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O4/2O2O
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
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '-') cnt++;
	}
	cout << (cnt == s.size() || !(cnt % (s.size() - cnt)) ? "YES" : "NO") << o_o;
}