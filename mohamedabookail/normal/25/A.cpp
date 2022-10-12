/**
*    author:  Mohamed AboOkail
*    created: 11/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector < int > a(n);
	int even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		even += !(a[i] & 1);
		odd += (a[i] & 1);
	}
	for (int i = 0; i < n; i++) {
		if(even < odd && !(a[i] & 1)) {
			cout << i + 1 << "\n";
			break;
		}
		if(even > odd && (a[i] & 1)) {
			cout << i + 1 << "\n";
			break;
		}
	}
}