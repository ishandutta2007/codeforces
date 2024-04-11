/**
*    author:  Mohamed Abo Okail
*    created: O4/O3/2O22
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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(all(a));
		ll sum1 = a[0] + a[1], sum2 = a[n - 1];
		bool ok = 0;
		if(sum1 < sum2) ok = 1;
		int l = 2, r = n - 2;
		while(l < r) {
			sum1 += a[l];
			sum2 += a[r];
			if(sum1 < sum2) {
				ok = 1;
				break;
			}
			l++;
			r--;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}