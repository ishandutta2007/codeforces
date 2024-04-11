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
		int n;
		cin >> n;
		long long ans = 0;
		long long a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			int oo;
			cin >> oo;
			if(oo % 3 == 0) a++;
			if(oo % 3 == 1) b++;
			if(oo % 3 == 2) c++;
		}
		if(a < n / 3) {
			if(c > n / 3) {
				long long cur = min(n / 3 - a, c - n / 3);
				ans += cur;
				c -= cur;
				a += cur;
			}
			if(a < n / 3) {
				ans += (n / 3 - a) * 2;
				b -= n / 3 - a;
			}
			a = n / 3;
		}
		if(b < n / 3) {
			if(a > n / 3) {
				long long cur = min(n / 3 - b, a - n / 3);
				ans += cur;
				a -= cur;
				b += cur;
			}
			if(b < n / 3) {
				ans += (n / 3 - b) * 2;
				c -= n / 3 - b;
			}
			b = n / 3;
		}
		if(c < n / 3) {
			if(b > n / 3) {
				long long cur = min(n / 3 - c, b - n / 3);;
				ans += cur;
				b -=  cur;
				c +=  cur;
			}
			if(c < n / 3) {
				ans += (n / 3 - c) * 2;
			}
		}
		cout << ans << "\n";
	}
}