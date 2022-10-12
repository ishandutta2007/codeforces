/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < pair < ll, ll > > v(n);
		bool bol = true;
		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());
		if(v[0].first == 0 && v[0].second == 0) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 1; i < n; i++) {
			if(v[i].first < v[i - 1].first || v[i].second < v[i - 1].second) {
				bol = false;
			}
		}

		if(!bol) {
			cout << "NO" << endl;
		}
		else {
			string s = "";
			for (int i = 0; i < v[0].first; i++) { s += 'R'; }
			for (int i = 0; i < v[0].second; i++) { s += 'U'; }
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < (v[i].first - v[i - 1].first); j++) { s += 'R'; }
				for (int j = 0; j < (v[i].second - v[i - 1].second); j++) { s += 'U'; }
			}
			cout << "YES" << endl << s << endl;
		}
	}
}