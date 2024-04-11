/**
*    author:  Mohamed AboOkail
*    created: 16/02/2O21
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
		long long n;
		cin >> n;
		long long ans = 0, cur = 3;
		for (int i = 3; i <= n; i += 2) {
			if(i * i - ((i * i - 1) / 2) <= n) {
				ans++;
			}
			else {
				break;
			}
		}
		cout << ans << "\n";
	}
}