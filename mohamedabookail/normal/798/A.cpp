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
	int cnt = 0, ind = s.size() - 1;
	for (int i = 0; i < s.size() / 2; i++) {
		if(s[i] != s[ind]) cnt++;
		ind--;
	}
	cout << (cnt == 1 || (!cnt && s.size() & 1) ? "YES" : "NO") << endl;
}