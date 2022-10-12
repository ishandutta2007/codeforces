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
	int t; cin >> t;
	while(t--) {
		string s, t, a; cin >> s >> t;
		map < char, int > mp;
		bool bol = 1, bol1 = 0;
		int cnt = 0, flag = t.size() - s.size();
		for (int i = 0; i < t.size(); i++) {
			mp[t[i]]++;
		}
		for (int i = 0; i < s.size(); i++) {
			if(mp[s[i]]) mp[s[i]]--;
			else bol = 0;
		}
		for (int i = 0; i < t.size(); i++) {
			if(mp[t[i]]) a.push_back(t[i]), mp[t[i]]--;
		}
		sort(a.begin(), a.end());
		for (int i = 0; i <= flag; i++) {
			string b;
			for (int j = 0; j < i; j++) {
				b.push_back(t[j]);
			}
			for (int j = t.size() - 1; j >= t.size() - (flag - i) ; j--) {
				b.push_back(t[j]);
			}
			sort(b.begin(), b.end());
			if(a == b) bol1 = 1;
		}
		
		cout << (!bol || !bol1 ? "NO" : "YES") << endl;
	}
}