/**
 *    author:  Mohamed Abo_Okail
 *    created: 21/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int n, k; string s; cin >> n >> k >> s;
	map < char, int > mp, flag;
	string t;
	for (int i = 0; i < sz(s); i++) {
		mp[s[i]] ++;
	}
	for (char ch = 'a'; ch <= 'z'; ch++) {
		if(k <= mp[ch]) {
			flag[ch] = k;
			break;
		}
		else {
			flag[ch] = mp[ch];
			k -= mp[ch];
		}
	}
	for (int i = 0; i < sz(s); i++) {
		if(flag[s[i]]) flag[s[i]] --;
		else t.push_back(s[i]);
	}
	cout << t << endl;
}