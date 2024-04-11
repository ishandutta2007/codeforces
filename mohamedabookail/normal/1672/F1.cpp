/**
*    author:  Mohamed Abo Okail
*    created: 23/O4/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < ll > a(n), b;
		map < ll , ll > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		for(auto it : mp) {
			b.push_back(it.first);
		}
		int indxL = 0;
		for (int i = 0; i < n; i++) {
			bool ok = 0;
			ll lo = 0, hi = sz(b) - 1, mid = 0, indx = -1;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				if(b[mid] > a[i]) {
					indx = mid;
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			if(indx != -1) {
				for (int j = indx; j < sz(b); j++) {
					if(mp[b[j]]) {
						cout << b[j] << ' ';
						mp[b[j]]--;
						ok = 1;
						break;
					}
				}
			}
			if(!ok) {
				for (int j = indxL; j < sz(b); j++) {
					if(mp[b[j]]) {
						cout << b[j] << ' ';
						mp[b[j]]--;
						if(mp[b[j]] == 0) {
							indxL = j + 1;
						}
						break;
					}
				}
			}
		}
		cout << endl;
	}
}