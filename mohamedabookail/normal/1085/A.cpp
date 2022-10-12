/**
 *    author:  Mohamed Abo_Okail
 *    created: 2O/O3/2O2O
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
	string s; cin >> s; string t = "";
	bool bol = 1; if(s.size() % 2) bol = 0;
	for (int i = 0; i < s.size(); i++) {
		if(bol) {
			t += s[s.size() - 1];
			t += s[i];
			s.pop_back();
		}
		else {
			t += s[i];
			if(s.size() - 1 != i) t += s[s.size() - 1];
			s.pop_back();
		}
	}
	reverse(t.begin(), t.end());
	cout << t << o_o;
}