/**
*    author:  Mohamed AboOkail
*    created: 29/01/2O21
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
		long long n, k;
		cin >> n >> k;
		if(k % n == 0 && k >= n) {
			cout << k / n << "\n";
		}
		else if(k < n){
			cout << (n % k == 0 ? 1 : 2) << "\n";
		}
		else {
			cout << k / n + 1 << "\n";
		}
	}
}