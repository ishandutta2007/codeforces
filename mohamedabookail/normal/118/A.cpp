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
	string s; cin >> s;
	char ar[] = {'a', 'o', 'y', 'e', 'u', 'i'};
	for (int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}
	for (int i = 0; i < s.size(); i++) {
		bool bol = 0;
		for (int j = 0; j < 6; j++) {
			if(s[i] == ar[j]) bol = 1;
		}
		if(!bol) cout << '.' << s[i];
	}
}