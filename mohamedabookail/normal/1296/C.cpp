/**
 *    author:  Mohamed Abo_Okail
 *    created: O4/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n; string s; cin >> n >> s;
		map < pair < ll, ll >, ll > mp, ans;
		mp[{0, 0}] = -1;
		ans[{0, 0}] = 1;
		ll x = 0, y = 0;
		ll a = 0, b = 0, mn = 1e10;
		for (int i = 0; i < n; i++) {
			if(s[i] == 'U') y++;
			if(s[i] == 'D') y--;
			if(s[i] == 'R') x++;
			if(s[i] == 'L') x--;
			ll aa = 0, bb = 0;
			if(mp[{x, y}] == 1) {
			    aa = ans[{x, y}] + 1; bb = i + 1;
				if(bb - aa < mn) {
				    mn = bb - aa;
				    a = ans[{x, y}] + 1; b = i + 1;
				}
			}
			if(mp[{x, y}] == -1) {
			    aa = ans[{x, y}]; bb = i + 1;
				if(bb - aa < mn) {
				    mn = bb - aa;
				    a = ans[{x, y}]; b = i + 1;
				}
			}
			mp[{x, y}] = 1;
			ans[{x, y}] = i + 1;
		}
		if(mn == 1e10) cout << -1 << o_o;
		else {
			cout << a << ' ' << b << o_o;
		}
	}
}