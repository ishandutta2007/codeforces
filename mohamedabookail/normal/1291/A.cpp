/**
 *    author:  Mohamed Abo_Okail
 *    created: O2/O2/2O2O
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
		string t = "";
		for (int i = 0; i < n; i++) {
			if((s[i] - '0') % 2) t += s[i];
		}
		if(t.size() > 1) cout << t[0] << t[1];
		else cout << -1;
		cout << o_o;
	}
}