/**
*    author:  Mohamed Abo Okail
*    created: O8/O9/2O22
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
		int mx = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] > mx) {
				ans = i + 1;
				mx = a[i];
			}
		}
		cout << ans << endl;
	}
}