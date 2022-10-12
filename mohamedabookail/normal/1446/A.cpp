/**
*    author:  Mohamed Abo_Okail
*    created: 15/11/2O2O
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
	//freopen("x.in", "r", stdin);
	int t; cin >> t;
	while(t--) {
		ll n, w; cin >> n >> w;
		vector < pair < ll, ll > > p;
		bool bol = 0;
		for (int i = 0; i < n; i++) {
			ll oo; cin >> oo;
			if(oo <= w) {
				p.push_back(make_pair(oo, i + 1));
			}
			if(oo >= (w + 1) / 2 && oo <= w && !bol) {
				cout << 1 << endl << i + 1 << endl;
				bol = 1;
			}
		}
		if(bol) continue;
		ll sum = 0;
		vector < ll > x;
		for (int i = 0; i < sz(p); i++) {
			sum += p[i].first;
			x.push_back(p[i].second);
			if(sum >= (w + 1) / 2 && sum <= w) break;
		}
		if(sum >= (w + 1) / 2 && sum <= w) {
			cout << sz(x) << endl;
			for(auto i : x) cout << i << ' '; cout << endl;
		}
		else cout << -1 << endl;
	}
}