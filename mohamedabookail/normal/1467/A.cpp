/**
*    author:  Mohamed AboOkail
*    created: 08/01/2O21
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
		string a = "0123456789", s = "9890123456789";
		for (int i = 0; i <= n; i++) {
			s += a;
		}
		cout << s.substr(0, n) << endl;
	}
}