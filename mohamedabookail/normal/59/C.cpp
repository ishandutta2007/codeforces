/**
 *    author:  Mohamed Abo_Okail
 *    created: 15/O6/2O2O
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
	int n; string s; cin >> n >> s;
	map < char, bool > mp;
	int indx = sz(s) - 1, indx1 = sz(s) - 1, cnt = 0, flag = 0;
	for (int i = 0; i < sz(s); i++) {
		if(s[i] != '?') mp[s[i]] = 1;
	}
	for (int i = 0; i < sz(s) / 2 + sz(s) % 2; i++) {
		if(s[i] == '?' && s[indx1] == '?') cnt++;
		indx1 --;
	}
	flag = max(cnt - (n - sz(mp)), 0);
	if(!mp['a']) flag ++;
	for (int i = 0; i < sz(s) / 2 + sz(s) % 2; i++) {
		if(s[i] == '?' && s[indx] != '?') s[i] = s[indx];
		if(s[i] != '?' && s[indx] == '?') s[indx] = s[i];
		if(s[i] == '?' && s[indx] == '?') {
			if(flag) {
				s[i] = 'a';
				s[indx] = 'a';
				mp['a'] = 1;
				flag --;
				indx --;
				continue;
			}
			for (char ch = 'a'; ch <= 'z'; ch++) {
				if(sz(mp) < n && !mp[ch]) {
					s[i] = ch;
					s[indx] = ch;
					mp[ch] = 1;
					break;
				}
				if(sz(mp) >= n && mp[ch]) {
					s[i] = ch;
					s[indx] = ch;
					break;
				}
			}
		}
		indx --;
	}
	string t = s; reverse(t.begin(), t.end());
	cout << (t == s && sz(mp) == n ? s : "IMPOSSIBLE") << endl;
}