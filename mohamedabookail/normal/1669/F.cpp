/**
*    author:  Mohamed Abo Okail
*    created: 21/O4/2O22
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
		ll n;
		cin >> n;
		vector < ll > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 0, l = 0, r = n - 1;
		ll sum1 = 0, sum2 = 0, cnt = 0;
		while(l <= r) {
			cnt++;
			if(sum1 <= sum2) {
				sum1 += a[l];
				l++;
			}	
			else {
				sum2 += a[r];
				r--;
			}
			if(sum1 == sum2) {
				ans = cnt;
			}
			
		}
		cout << ans << endl;
	}
}