
/**
*    author:  Mohamed Abo Okail
*    created: 11/O7/2O21
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
		vector < ll > a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		ll x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] > b[i]) {
				x += a[i] - b[i];
			}
			if(b[i] > a[i]) {
				y += b[i] - a[i];
			}
		}
		if(x != y) {
			cout << -1 << endl;
			continue;
		}
		vector < pair <int , int > > ans;
		for (int i = 0; i < n; i++) {
			if(a[i] < b[i]) {
				while(a[i] != b[i]) {
					a[i]++;
					for (int j = 0; j < n; j++) {
						if(a[j] > b[j]) {
							ans.push_back(make_pair(j + 1, i + 1));
							a[j]--;
							break;
						} 
					}
				}
			}
		}
		cout << sz(ans) << endl;
		for (int i = 0; i < sz(ans); i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}
}