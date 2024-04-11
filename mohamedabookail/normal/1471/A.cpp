/**
*    author:  Mohamed AboOkail
*    created: 11/01/2O21
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
		long long n, x;
		cin >> n >> x;
		long long sum = 0, mx = 0, mn = 0;
		for (int i = 0; i < n; i++) {
			long long oo;
			cin >> oo;
			mx += (oo + x - 1) / x;
			sum += oo;
		}
		mn = (sum + x - 1) / x;
		cout << mn << ' ' << mx << "\n";
	}
}