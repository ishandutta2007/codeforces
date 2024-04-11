/**
*    author:  Mohamed Abo Okail
*    created: 2O/1O/2O21
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
		ll n, k; cin >> n >> k;
		vector < ll > a(n);
		map < ll , int > mp;
		set < ll > st;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			st.insert(a[i]);
		}
		sort(all(a));
		ll mex = n;
		for (int i = 0; i < n; i++) {
			if(a[i] != i) {
				mex = i;
				break;
			}
		}
		if(mex == n) {
			cout << sz(st) + k << endl;
		}
		else {
			cout << sz(st) + (k && !mp[(a[n - 1] + mex + 1) / 2]) << endl;
		}
	}
}