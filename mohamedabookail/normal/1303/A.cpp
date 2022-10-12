/**
 *    author:  Mohamed Abo_Okail
 *    created: 12/O2/2O2O
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
	ll t; cin >> t;
	while(t--) {
		string s; cin >> s;
		ll nemo = 0, inx1 = -1, inx2 = -1;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == '1') {
				inx1 = i;
				break;
			}
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			if(s[i] == '1') {
				inx2 = i;
				break;
			}
		}
		if(inx1 == -1 && inx2 == -1) {
			cout << 0 << o_o;
			continue;
		}
		for (int i = inx1; i <= inx2; i++) {
			if(s[i] == '0') nemo++;
		}
		
		cout << nemo << o_o;
	}
}