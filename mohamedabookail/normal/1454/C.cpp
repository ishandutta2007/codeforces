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
		vector < ll > a(n), b;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		b.push_back(a[0]);
		for (int i = 1; i < n; i++) {
			if(a[i] != b.back()) {
				b.push_back(a[i]);
			}
		}
		n = sz(b);
		a.clear();
		a = b;
		map < ll, ll > mp1, mp2, mp3;
		for (int i = 0; i < n; i++) {
			mp1[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if(!mp2[a[i]]) {
				mp2[a[i]] = i + 1;
			}
		}
		for (int i = n - 1; i >= 0 ; i--) {
			if(!mp3[a[i]]) {
				mp3[a[i]] = i + 1;
			}
		}
		ll mn = 1e9;
		for(auto it : mp1) {
			ll flag = it.first;
			if(mp1[flag] == 1) {
				if((mp2[flag] == 1 || mp3[flag] == n) && n == 1) {
					mn = 0;
				}
				else if(mp2[flag] == 1 || mp3[flag] == n) {
					mn = min(mn, 1LL);
				}
				else {
					mn = min(mn, 2LL);
				}
			}
			else {
				ll cur = 0;
				if(mp2[flag] != 1) cur++;
				if(mp3[flag] != n) cur++;
				cur += mp1[flag] - 1;
				mn = min(mn, cur);
			}
		}
		cout << mn << endl;
	}
}