/**
 *    author:  Mohamed Abo_Okail
 *    created: 17/O3/2O2O
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
	int n, m; cin >> n >> m;
	map < string, int > mp;
	vector < string > v(n);
	string t = "", x = "";
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
	}
	for (int i = 0; i < n; i++) {
		string s = v[i];
		reverse(s.begin(), s.end());
		if(mp[s] && s != v[i]) {
			t += v[i];
			mp[s]--;
			mp[v[i]]--;
		}
		if(s == v[i]) {
			if(mp[s] * m > mx) {
				for (int i = 0; i < mp[s]; i++) {
					x += s;
				}
				mx = x.size();
			}
			mp[s] = 0;
		}
		if(mp[s] && mp[v[i]] && s != v[i]) i--;
	}
	string s = t;
	reverse(s.begin(), s.end());
	cout << t.size() * 2 + x.size() << o_o;
	cout << t + x + s << o_o;
}