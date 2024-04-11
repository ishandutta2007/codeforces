/**
*    author:  Mohamed AboOkail
*    created: 13/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		long long x, y, k;
		cin >> x >> y >> k;
		long long cur = k + y * k - 1;
		long long ans = 0;
		ans = (cur + x - 2) / (x - 1) + k;
		cout << ans << "\n";
	}
}