/**
*    author:  Mohamed AboOkail
*    created: 28/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
long long _gcd(long long x, long long y) {
	return (!y ? x : _gcd(y, x % y));
}

int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;
	while(t--) {
		long long n, k;
		cin >> n >> k;
		vector < long long > a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long g = 0;
		for (int i = 1; i < n; i++) {
			g = _gcd(g, a[i] - a[i - 1]);
		}
		cout << (!((k - a[0]) % g) ? "YES" : "NO") << "\n";
	}
}