/**
*    author:  Mohamed AboOkail
*    created: 14/02/2O21
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
		int n, k;
		cin >> n >> k;
		vector < int > a(n * k);
		for (int i = 0; i < n * k; i++) {
			cin >> a[i];
		}
		long long ans = 0;
		int size = n * k;
		for (int i = 0; i < size; i++) {
			if(n == 2) {
				if(i % 2 == 0) ans += a[i];
			}
			else if(n & 1) {
				int x = n / 2, y = n / 2 + 1;
				size -= y;
				ans += a[size];
				i += x - 1;
			}
			else {
				int x = n / 2 - 1, y = n / 2 + 1;
				size -= y;
				ans += a[size];
				i += x - 1;
			}
		}
		cout << ans << "\n";
	}
}