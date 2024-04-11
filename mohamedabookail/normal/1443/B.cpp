/**
*    author:  Mohamed Abo_Okail
*    created: O2/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll a, b; cin >> a >> b;
		string s; cin >> s;
		
		while(sz(s) && s.back() == '0') {
			s.pop_back();
		}
		if(!sz(s)) {
			cout << 0 << endl;
			continue;
		}
		reverse(all(s));
		while(s.back() == '0') {
			s.pop_back();
		}
		reverse(all(s));

		vector < ll > x;
		ll ans = 0,  cnt = 1;
		for (int i = 1; i < sz(s); i++) {
			if(s[i] != s[i - 1]) {
				x.push_back(cnt);
				cnt = 0;
			}
			cnt++;
		}
		x.push_back(cnt);
		if(sz(x) == 1) {
			cout << a << endl;
			continue;
		}
		bool bol = 0;
		for (int i = 1; i < sz(x); i += 2) {
			ll cur1 = a * 2, cur2 = x[i] * b + a;
			if(cur2 <= cur1) {
				ans += cur2;
				if(bol) ans -= a;
				bol = 1;
			}
			else {
				if(!bol) ans += a;
				bol = 0;
			}
		}
		if(!bol) ans += a;
		cout << ans << endl;
	}
}