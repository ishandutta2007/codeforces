/**
*    author:  Mohamed Abo Okail
*    created: 12/O4/2O22
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
		vector < ll > a(n);
		map < ll , ll > mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		vector < pair < ll , ll > > any;
		ll mex = 0, cnt = 0;
		for (int i = 0; i <= n; i++) {
			if(mex == -1) {
				cout << mex << ' ';
				continue;
			}
			mex = mp[i] + cnt;
			cout << mex << ' ';
			if(mp[i] > 1) {
				any.push_back(make_pair(i, mp[i] - 1));
			}
			if(mp[i] == 0) {
				if(any.empty()) {
					mex = -1;
				}
				else {
					cnt += i - any.back().first;
					any.back().second--;
					mp[i] = 1;
					if(any.back().second == 0) {
						any.pop_back();
					}
				}
			}
		}
		cout << endl;
	}
}