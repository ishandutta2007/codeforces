/**
*    author:  Mohamed Abo Okail
*    created: 19/O9/2O22
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
		int n;
		cin >> n;
		vector < ll > a(n), cur(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] & 1) {
				cur[i] = 1;
			}
			else {
				cur[i] = 0;
			}
		}
		vector < pair < ll , ll > > ans;
		if(cur[0] == 1 && cur[n - 1] == 1) {
			for (int i = 0; i < n - 1; i++) {
				if(cur[i] == 1) {
					ans.push_back(make_pair(i + 1, n));
				}
			}
			for (int i = 0; i < n; i++) {
				if(cur[i] == 0) {
					ans.push_back(make_pair(1 , i + 1));
				}
			}
		}

		if(cur[0] == 0 && cur[n - 1] == 0) {
			for (int i = 0; i < n - 1; i++) {
				if(cur[i] == 0) {
					ans.push_back(make_pair(i + 1, n));
				}
			}
			for (int i = 0; i < n; i++) {
				if(cur[i] == 1) {
					ans.push_back(make_pair(1 , i + 1));
				}
			}
		}

		if(cur[0] == 0 && cur[n - 1] == 1) {
			int flag = 0;
			for (int i = n - 1; i >= 0 ; i--) {
				if(cur[i] == 0) {
					flag = i + 1;
					break;
				}
			}
			for (int i = 0; i < n; i++) {
				if(i == flag - 1) continue;
				if(cur[i] == 0) {
					ans.push_back(make_pair(i + 1, flag));
				}
			}
			for (int i = 0; i < n; i++) {
				if(cur[i] == 1) {
					ans.push_back(make_pair(1 , i + 1));
				}
			}
		}

		if(cur[0] == 1 && cur[n - 1] == 0) {
			int flag = 0;
			for (int i = n - 1; i >= 0 ; i--) {
				if(cur[i] == 1) {
					flag = i + 1;
					break;
				}
			}
			for (int i = 0; i < n; i++) {
				if(i == flag - 1) continue;
				if(cur[i] == 1) {
					ans.push_back(make_pair(i + 1, flag));
				}
			}
			for (int i = 0; i < n; i++) {
				if(cur[i] == 0) {
					ans.push_back(make_pair(1, i + 1));
				}
			}
		}

		cout << sz(ans) << endl;
		for (int i = 0; i < sz(ans); i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}
}