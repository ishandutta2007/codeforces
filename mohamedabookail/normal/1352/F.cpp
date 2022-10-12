/**
 *    author:  Mohamed Abo_Okail
 *    created: 18/O5/2O2O
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
		int a, b, c; cin >> a >> b >> c;
		string s;
		if(!b) {
			if(a) {
				s.assign(a + 1, '0');
			}
			else {
				s.assign(c + 1, '1');
			}
		}
		else {
			s = "01"; b--;
			int flag = 1, cur = b + 1;
			while(b--) {
				if(flag == 1) {
					s.push_back('0');
				}
				else {
					s.push_back('1');
				}
				flag *= -1;
			}
			string t(a, '0');
			s = t + s;
			t.clear();
			t.assign(c, '1');
			if(cur & 1) {
				s += t;
			}
			else {
				s.pop_back();
				s += t;
				s.push_back('0');
			}
		}
		cout << s << endl;
	}
}