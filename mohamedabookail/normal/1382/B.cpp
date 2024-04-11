/**
*    author:  Mohamed Abo_Okail
*    created: 21/O7/2O2O
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
	return (x / _gcd(x, y) * y);
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > v(n);
		bool bol = 1;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if(v[i] == 1) cnt++;
		}
		if(!cnt) {
			cout << "First" << endl;
			continue;
		}
		for (int i = 0; i < n - 1; i++) {
			if(v[i] == 1) bol = !bol;
			else {
				int flag = 0;
				for (int j = i + 1; j < n - 1; j++) {
					if(v[j] == 1) flag++;
					else break;
				}
				if(flag & 1) bol = !bol;
			}
		}
		cout << (bol ? "First" : "Second") << endl;
	}
}