/**
*    author:  Mohamed AboOkail
*    created: 04/01/2O21
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
		long long a, b, n;
		cin >> a >> b >> n;
		long long x = a, y = b;
		while(a) {
			if(a % 2 == 0) {
				a /= 2;
				if(a % 2 != 0) break;
			}
			if(a % 2 != 0) {
				break;
			}
		}
		while(b) {
			if(b % 2 == 0) {
				b /= 2;
				if(b % 2 != 0) break;
			}
			if(b % 2 != 0) {
				break;
			}
		}
		cout << ((x / a) * (y / b) >= n ? "YES" : "NO") << endl;
	}
}