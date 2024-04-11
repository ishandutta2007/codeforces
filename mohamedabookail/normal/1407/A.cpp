/**
*    author:  Mohamed Abo_Okail
*    created: O8/O9/2O2O
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
		ll n; cin >> n;
		ll one = 0, zero = 0;
		for (int i = 0; i < n; i++) {
			int oo; cin >> oo;
			if(oo) one++;
			else zero++;
		}
		int idx = n / 2;
		if(one == n) idx = n;
		if(idx & 1 && one > zero) idx++;
		cout << idx << endl;
		for (int i = 0; i < idx; i++) {
			if(i) cout << ' ';
			if(one > zero) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		cout << endl;
	}
}