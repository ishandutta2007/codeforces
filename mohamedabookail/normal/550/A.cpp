/**
 *    author:  Mohamed Abo_Okail
 *    created: O7/O6/2O2O
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
	string s; cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.size(); i++) {
		if(i + 1 < s.size() && i + 2 < s.size()) {
			if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A') {
				a++; i += 2;
				continue;
			}
			if(s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B') {
				a++; i += 2;
				continue;
			}
		}
		if(i + 1 < s.size()) {
			if(s[i] == 'A' && s[i + 1] == 'B') {
				b++; i++;
				continue;
			}
			if(s[i] == 'B' && s[i + 1] == 'A') {
				c++; i++;
				continue;
			}
		}
	}
	cout << (((b && c) || (a && b) || (a && c) || a > 1) ? "YES" : "NO") << endl;
}