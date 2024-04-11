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
	string s; int n; cin >> s >> n;
	int cnt = 0, a = 0, b = 0;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] != '?' && s[i] != '*') cnt++;
	}
	a = max(n - cnt, 0);
	b = max(cnt - n, 0);
	string t = "";
	for (int i = 0; i < s.size(); i++) {
		if(a > 0) {
			if(s[i] == '*' && t.size()) {
				while(a--) {
					t.push_back(s[i - 1]);
				}
			}
		}
		if(b > 0) {
			if((s[i] == '?' || s[i] == '*') && t.size()) {
				t.pop_back();
				b--;
			}
		}
		if(s[i] >= 'a' && s[i] <= 'z') t += s[i];
	}
	cout << (t.size() == n ? t : "Impossible") << o_o;
}