/**
*    author:  Mohamed Abo_Okail
*    created: 12/O7/2O2O
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
		int n; cin >> n;
		vector < int > v(n);
		int indx = 0;
		bool bol = 0, bol2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			bol2 = 0;
			for (int j = i + 1; j < n; j++) {
				if(v[j] < v[i]) {
					indx = j + 1;
					bol2 = 1;
				}
			}
			for (int k = i - 1; k >= 0; k--) {
				if(v[k] < v[i] && bol2) {
					cout << "YES" << endl;
					cout << k + 1 << ' ' << i + 1 << ' ' << indx << endl;
					bol = 1;
					break;
				}
			}
			if(bol) break;
		}
		if(!bol) cout << "NO" << endl;
	}
}