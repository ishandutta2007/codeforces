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
	int cnt = 0;
	string t;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] >= 'a' && s[i] <= 'z') {
			t.push_back(s[i] - 32);
		}
		else {
			t.push_back(s[i] + 32);
			cnt++;
		}
	}
	if(cnt == s.size()) cout << t << endl;
	else if(cnt == s.size() - 1 && s[0] >= 'a' && s[0] <= 'z') cout << t << endl;
	else cout << s << endl;
}