#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t,a;
	cin >> t;
	while(t--) {
		cin >> a;
		if(a % 2050 != 0) cout << "-1" <<endl;
		else {
			a /= 2050;
			int ans = 0;
			while(a) ans += a % 10,a /= 10;
			cout << ans << endl;
		}
	}
	return 0;
}