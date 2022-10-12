/**
*    author:  Mohamed Abo Okail
*    created: 28/11/2O21
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
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll cnt = 0, sum = 0, x = a[i];
			for (int j = 0; j < n; j++) {
				if(i == j) continue;
				ll cur = a[j];
				while(cur % 2 == 0) {
					cur /= 2;
					cnt++;
				}
				sum += cur;
			}
			for (int j = 0; j < cnt; j++) {
				x *= 2;
			}
			sum += x;
			ans = max(ans, sum);
		}
		cout << ans << endl;
	}
}