/**
*    author:  Mohamed AboOkail
*    created: 12/02/2O21
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
		long long a, b;
		cin >> a >> b;
		long long ans = 1e9;
		for (int i = b + (b == 1); i < b + 100; i++) {
			long long cur = a, cnt = i - b;
			while(cur) {
				cur /= i;
				cnt++;
			}
			ans = min(ans, cnt);
		}
		cout << ans << "\n";
	}
}