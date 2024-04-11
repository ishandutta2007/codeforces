/**
*    author:  Mohamed AboOkail
*    created: 10/01/2O21
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
		long long a, b, c;
		cin >> a >> b >> c;
		if(c < a || c > b) {
			cout << c << endl;
			continue;
		}
		cout << (b / c + 1) * c << endl;
	}
}