/**
*    author:  Mohamed AboOkail
*    created: 25/01/2O21
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
		if(n & 1) {
			cout << "YES" << "\n";
			continue;
		}
		while(!(n & 1)) {
			n /= 2;
		}
		cout << ((n & 1) && n != 1 ? "YES" : "NO") << "\n";
	}
}