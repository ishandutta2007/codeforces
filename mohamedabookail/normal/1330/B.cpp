/**
 *    author:  Mohamed Abo_Okail
 *    created: O4/O4/2O2O
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
		ll n; cin >> n;
		vector < ll > v(n);
		map < ll, int > mp;
		bool bol = 1;
		ll mx = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mx = max(v[i], mx);
			mp[v[i]]++;
			if(mp[v[i]] == 3) bol = 0;
		}
		if(!bol) cout << 0 << o_o;
		else {
			ll mxx = -1;
			for (int i = 0; i < n; i++) {
				if(mp[v[i]] == 2 && v[i] > mxx) mxx = v[i];
			}
			if(mxx == -1 || mx + mxx != n) {
				cout << 0 << o_o;
			}
			else {
				bool bol2 = 1;
				for (int i = 1; i <= mxx; i++) {
					if(mp[i] <= 1) bol2 = 0;
				}
				if(!bol2) cout << 0 << o_o;
				else {
					set < ll > st1, st2;
					pair < ll, ll > p1, p2;
					ll a = -1, b = -1, c = 0, cnt = 0;
					for (int i = 0; i < n; i++) {
						a = max(a, v[i]);
						st1.insert(v[i]);
						if(st1.size() == a && i + 1 == a && (a == mx || a == mxx)) {
							p1.first = a;
							p1.second = n - a;
							c++;
							break;
						}
					}
					if(c) {
						for (int i = n - 1; i >= 0 ; i--) {
							b = max(b, v[i]);
							st2.insert(v[i]);
							cnt++;
							if(st2.size() == b && cnt == b && (b == mx || b == mxx)) {
								p2.first = n - b;
								p2.second = b;
								if(p1.first == p2.first) break;
								c++;
								break;
							}
						}
					}
					cout << c << o_o;
					if(c >= 1) {
						cout << p1.first << ' ' << p1.second << o_o;
					}
					if(c == 2) {
						cout << p2.first << ' ' << p2.second << o_o;
					}
				}
			}
		}
	}
}