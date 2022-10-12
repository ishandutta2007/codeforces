/**
*    author:  Mohamed Abo Okail
*    created: 19/O4/2O22
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
		int n, m;
		cin >> n >> m;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		if(n == 1) {
			cout << (a[0] + 1 <= m ? "YES" : "NO") << endl;
			continue;
		}
		ll mxNeed = 0;
		for (int i = 0; i < n - 1; i++) {
			mxNeed += max(a[i], a[i + 1]) + 1;
		}
		mxNeed += max(a[0], a[n - 1]) + 1;
		cout << (mxNeed <= m ? "YES" : "NO") << endl;
	}
}