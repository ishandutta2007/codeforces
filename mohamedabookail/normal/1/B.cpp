/**
 *    author:  Mohamed Abo_Okail
 *    created: O8/O6/2O2O
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
 
ll to_String(string a) {
	ll num = 0;
	for (int i = 0; i < a.size(); i++) {
		num = num * 10 + (a[i] - '0');
	}
	return num;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		string s, a, b, c; cin >> s;
		bool bol1 = 0, bol2 = 0, bol3 = 1;
		ll flag = 0, ind1 = 0, ind2 = 0;
		s = '0' + s;
		ind1 = s.find('R');
		ind2 = s.find('C');
		if(!ind1 || !ind2) bol3 = 0;
		if(s[ind1 + 1] < '1' || s[ind1 + 1] > '9') bol3 = 0;
		if(s[ind2 + 1] < '1' || s[ind2 + 1] > '9') bol3 = 0;
		if(bol3) {
			for (int i = 0; i < s.size(); i++) {
				if(s[i] == 'R') {
					bol1 = 1;
					continue;
				}
				if(s[i] == 'C') {
					bol2 = 1;
					bol1 = 0;
					continue;
				}
				if(bol1) b.push_back(s[i]);
				if(bol2) a.push_back(s[i]);
			}
			flag = to_String(a);
			while(flag) {
				if(flag % 26 == 0) {
					c.push_back('Z');
					flag -= 26;
				}
				else {
					c.push_back('A' + (flag % 26 - 1));
					flag -= (flag % 26);
				}
				flag /= 26;
			}
			reverse(c.begin(), c.end());
			cout << c << b << endl;
		}
		else {
			for (int i = 1; i < s.size(); i++) {
				if(s[i] >= 'A' && s[i] <= 'Z') {
					a.push_back(s[i]);
				}
				else {
					b.push_back(s[i]);
				}
			}
			for (int i = 0; i < a.size(); i++) {
				flag *= 26;
				flag += (a[i] - 'A') + 1;
			}
			cout << 'R' << b << 'C' << flag << endl;
		}
	}
}