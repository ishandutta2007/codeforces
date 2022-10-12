/**
*    author:  Mohamed AboOkail
*    created: 14/01/2O21
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
		for (int i = 1; i < k - (n - k); i++) {
			cout << i << ' ';
		}
		for (int i = k; i >= k - (n - k); i--) {
			cout << i << ' ';
		}
		cout << "\n";
	}
}