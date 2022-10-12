/**
*    author:  Mohamed AboOkail
*    created: 25/12/2O2O
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int ar[4];
		cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];
		sort(ar, ar + 4);
		cout << ar[0] * ar[2] << endl;
	}
}