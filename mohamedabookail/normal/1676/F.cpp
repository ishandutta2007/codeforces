/**
*    author:  Mohamed Abo Okail
*    created: 1O/O5/2O22
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
	
	map < int , int > mp;
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector < int > a(n), flag;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if(mp[a[i]] >= k) {
				flag.push_back(a[i]);
			}
			mp[a[i]] = 0;
		}
		if(!sz(flag)) {
			cout << -1 << endl;
			continue;
		}
		sort(all(flag));
		ll l = flag[0], r = flag[0], cnt = 1;
		for (int i = 1; i < sz(flag); i++) {
			if(flag[i] == flag[i - 1] + 1) {
				cnt++;
				if(cnt > r - l) {
					r = flag[i];
					l = flag[i] - cnt + 1;
				}
			}
			else {
				cnt = 1;
			}
		}
		cout << l << ' ' << r << endl;
		mp.clear();
	}
}