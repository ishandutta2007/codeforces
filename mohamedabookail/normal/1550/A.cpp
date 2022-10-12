/**
*    author:  Mohamed Abo Okail
*    created: 14/O7/2O21
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
		ll n; cin >> n;
		if(n <= 2) {
			cout << n << endl;
			continue;
		}
		if(n == 3 || n == 4) {
			cout << 2 << endl;
			continue;
		}
		ll ans = 1, sum = 1, x = 1;
		while(sum < n) {
			if(sum + x * 2 > n) break;
			sum += (x * 2);
			ans++;
			x++;
		}
		if(n - sum > ans - 1) {
			ans++;
		}
		cout << ans << endl;
	}
}