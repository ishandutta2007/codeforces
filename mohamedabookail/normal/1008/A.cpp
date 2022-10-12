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
	string s; cin >> s;
	char ar[] = {'a', 'o', 'u', 'i', 'e'};
	if(s.size() == 1) s += '0';
	for (int i = 1; i < s.size(); i++) {
		bool bolA = 0, bolB = 0;
		for (int j = 0; j < 5; j++) {
			if(s[i - 1] == ar[j]) bolA = 1;
			if(s[i] == ar[j]) bolB = 1;
		}
		if(i == s.size() - 1 && !bolB && s[i] != 'n' && s[i] != '0') return cout << "NO", 0;
		if(!bolA && !bolB && s[i - 1] != 'n') return cout << "NO", 0;
	}
	cout << "YES" << o_o;
}