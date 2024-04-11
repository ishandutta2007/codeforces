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
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			if(x % k == 0 || x >= 100) {
				cout << "YES" << "\n";
				continue;
			}
			long long cur = x % k;
			bool ok = 0;
			for (int j = 0; j < x / k; j++) {
				cur += k;
				long long flag = cur;
				while(flag) {
					if(flag % 10 == k) {
						ok = 1;
						break;
					}
					flag /= 10;
				}
				if(ok) break;
			}
			cout << (ok ? "YES" : "NO") << "\n";
		}
	}
}