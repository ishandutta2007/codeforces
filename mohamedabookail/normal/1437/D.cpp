/**
*    author:  Mohamed Abo_Okail
*    created: 27/1O/2O2O
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
		int n; cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 1, cnt = 0, cur = 0;
		for (int i = 1; i < n; i++) {
			if(a[i] > a[i - 1]) {
				cnt++;
			}
			else {
				if(cur) cur--;
				else {
					ans++;
					cur = cnt - 1;
				}
			}
		}
		cout << ans + (cur == cnt) << endl;
	}
}