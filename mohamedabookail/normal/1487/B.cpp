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
		long long n, k;
		cin >> n >> k;
		if(n & 1) {
			k += (k - 1) / (n / 2) - 1;
		}
		else {
			k--;
		}
		cout << k % n + 1 << "\n";
	}
}