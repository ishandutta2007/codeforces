/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O3/2O2O
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
	int n = s.size(), inx = n - 1;
	vector < int > v;
	for (int i = 0; i < n; i++) {
		if(s[i] == '(' && s[inx] == ')') {
			v.push_back(i + 1);
			v.push_back(inx + 1);
			inx--;
			n--;
		}
		else if(s[i] == '(' && s[inx] == '(') {
			inx--;
			i--;
			n--;
		}
	}
	sort(v.begin(), v.end());
	if(v.size()) cout << 1 << o_o;
	cout << v.size() << o_o;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if(i != v.size() - 1) cout << ' ';
	}
}