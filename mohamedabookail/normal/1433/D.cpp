/**
*    author:  Mohamed Abo_Okail
*    created: 21/1O/2O2O
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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector < pair < int, int > > p;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if(a[i] != a[j]) {
					p.push_back(make_pair(i + 1, j + 1));
				}
			}
		}
		vector < pair < int, int > > pp;
		map < ll, bool > mp;
		for (int i = 0; i < sz(p); i++) {
			if(mp[p[i].first] + mp[p[i].second] < 2) {
				pp.push_back(make_pair(p[i].first, p[i].second));
				mp[p[i].first] = 1;
				mp[p[i].second] = 1;
			}
			if(sz(pp) == n - 1) break;
		}
		if(sz(pp) == n - 1) {
			cout << "YES" << endl;
			for (int i = 0; i < n - 1; i++) {
				cout << pp[i].first << ' ' << pp[i].second << endl;
			}
		}
		else cout << "NO" << endl;
	}
}