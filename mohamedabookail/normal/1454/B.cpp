/**
*    author:  Mohamed Abo_Okail
*    created: 24/11/2O2O
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
		vector < ll > a(n);
		map < ll, ll > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		bool bol = 0;
		int mn = 1e9, idx = 0;
		for (int i = 0; i < n; i++) {
			if(mp[a[i]] == 1) {
				if(a[i] <= mn) {
					if(a[i] == mn) idx = min(idx, i + 1);
					else idx = i + 1;
					bol = 1;
					mn = a[i];
				}
			}
		}
		cout << (bol ? idx : -1) << endl;
	}
}