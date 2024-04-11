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

int _toString(string s) {
	int sm = 0;
	for (int i = 0; i < s.size(); i++) {
		sm = sm * 10 + (s[i] - '0');
	}
	return sm;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int a, b, c; cin >> a >> b;
	string s1, s2, s3;
	c = a + b;
	while(a) {
		if(a % 10) s1.push_back(a % 10 + '0');
		a /= 10;
	}
	while(b) {
		if(b % 10) s2.push_back(b % 10 + '0');
		b /= 10;
	}
	while(c) {
		if(c % 10) s3.push_back(c % 10 + '0');
		c /= 10;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	a = _toString(s1);
	b = _toString(s2);
	c = _toString(s3);
	cout << (a + b == c ? "YES" : "NO") << endl;
}